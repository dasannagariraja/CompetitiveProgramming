//raja1999

/*	Idea: compress all the values of leaves to the range [0,n].And maintain a segment tree which has the minimum 
	absolute difference of  elements present in that range,maximum element present in that range,and minimum element
	present in the range.
	Now using dsu on trees,at every time we have all ithe leaves values in its subtree updated in segment tree
	and get the minimum abolute difference.
*/
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);
int siz[50005];
struct segtree{
	int a,b,c;
}st[200005];
vector<vi>adj(50005);
int cnt[50005],a[50005],ans[50005]				;
map<int,int>mapi;
map<int,int>::iterator it;
int c=0;
int dfs(int u,int p){
	int i;
	siz[u]=1;
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			dfs(adj[u][i],u);
			siz[u]+=siz[adj[u][i]];
		}
	}
}
int build(int s,int e,int node){
	if(s==e){
		st[node].a=inf;
		st[node].b=-inf;
		st[node].c=inf;
		return 0;
	}
	int mid=(s+e)/2;
	build(s,mid,2*node);
	build(mid+1,e,2*node+1);
	st[node].a=min(st[2*node].a,st[2*node+1].a);
	st[node].a=min(st[node].a,(st[2*node+1].c-st[2*node].b));
	st[node].b=max(st[2*node].b,st[2*node+1].b);
	st[node].c=min(st[2*node].c,st[2*node+1].c);
	return 0;
}
int update(int pos,int x,int y,int s,int e,int node){
	if(pos>e||pos<s){
		return 0;
	}
	if(s==e){
		st[node].b=x;
		st[node].c=y;
		return 0;
	}
	int mid=(s+e)/2;
	update(pos,x,y,s,mid,2*node);
	update(pos,x,y,mid+1,e,2*node+1);
	st[node].a=min(st[2*node].a,st[2*node+1].a);
	st[node].a=min(st[node].a,(st[2*node+1].c-st[2*node].b));
	st[node].b=max(st[2*node].b,st[2*node+1].b);
	st[node].c=min(st[2*node].c,st[2*node+1].c);
	return 0;
}
int add(int u,int p){
	int i;
	if(adj[u].size()==1&&adj[u][0]==p){
		cnt[mapi[a[u]]]++;
		if(cnt[mapi[a[u]]]==1){
			update(mapi[a[u]],a[u],a[u],0,c-1,1);
		}
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			add(adj[u][i],u);
		}
	}
}
int remove(int u,int p){
	int i;
	if(adj[u].size()==1&&adj[u][0]==p){
		cnt[mapi[a[u]]]--;
		if(cnt[mapi[a[u]]]==0){
			update(mapi[a[u]],-1*inf,inf,0,c-1,1);
		}
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			remove(adj[u][i],u);
		}
	}
}
int dsutree(int u,int p){
	int id=-1,maxx=0,i;
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			if(siz[adj[u][i]]>maxx){
				maxx=siz[adj[u][i]];
				id=i;
			}
		}
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p&&i!=id){
			dsutree(adj[u][i],u);remove(adj[u][i],u);
		}
	}
	if(id!=-1)
	dsutree(adj[u][id],u);
	rep(i,adj[u].size()){
		if(adj[u][i]!=p&&i!=id){
			add(adj[u][i],u);
		}
	}
	if(adj[u].size()==1&&adj[u][0]==p){
		cnt[mapi[a[u]]]++;
		if(cnt[mapi[a[u]]]==1){
			update(mapi[a[u]],a[u],a[u],0,c-1,1);
		}
	}
	ans[u]=st[1].a;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,m,i,p,val;
	cin>>n>>m;
	rep(i,n-1){
		cin>>p;
		p--;
		adj[i+1].pb(p);
		adj[p].pb(i+1);
	}
	rep(i,m){
		cin>>a[n-m+i];
		mapi[a[n-m+i]]=1;
	}
	c=0;
	for(it=mapi.begin();it!=mapi.end();it++){
		it->ss=c;
		//inv[c]=it->ff;
		c++;
	}
	build(0,c-1,1);
	dfs(0,-1);
	dsutree(0,-1);
	val=(1LL<<31LL);
	int val1=2000005;
	rep(i,n-m){
		if(ans[i]>=val1){
			//cout<<"hi<"<<endl;	
			ans[i]=val-1;
		}
		cout<<ans[i]<<" ";
	}
	cout<<endl;
} 
	
