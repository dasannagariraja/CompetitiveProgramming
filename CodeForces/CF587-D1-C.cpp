/*
 	Idea:
 	similar to how we calculate lca using binary lifting method(by storing parents at distance of powers of 2)
 	,we can also store least 10 indices  correspondingly.And then find overall least 10 indices by finding lca(u,v)
 	and merging the least 10 indices in both u to lca path,and v to lca path.
*/

//raja1999
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
vi ve;
int par[100005][20],lev[100005],n;
vector< vector< vector< int> > >ans;
vector<vi> adj(100005),vec(100005);
vi merge(vi a,vi b){
	vi temp;
	int i;
	ve.clear();
	rep(i,a.size()){
		temp.pb(a[i]);
	}
	rep(i,b.size()){
		temp.pb(b[i]);
	}
	sort(all(temp));
	rep(i,min((int)temp.size(),10)){
		ve.pb(temp[i]);
	}
	return ve;
}
int dfs(int u,int p,int l){
	int i;
	par[u][0]=p;
	if(p!=-1){
		ans[u][0]=vec[u];
	}
	else{
		ans[u][0]=vec[u];
	}
	lev[u]=l;
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			dfs(adj[u][i],u,l+1);
		}
	}
}
int precomp(){
	int i,j;		
	f(i,1,20){
		rep(j,n){
			if(par[j][i-1]==-1){
				par[j][i]=-1;
				continue;
			}
			par[j][i]=par[par[j][i-1]][i-1];
			if(par[j][i]!=-1){
				ans[j][i]=merge(ans[j][i-1],ans[par[j][i-1]][i-1]);
			}
		}
	}
}
int compute(int u,int v,int a){
	if(lev[u]<lev[v]){
		swap(u,v);

	}
	vi res;
	res.clear();
	int i;
	fd(i,19,0){
		if(lev[u]-(1<<i)>=lev[v]){
			res=merge(res,ans[u][i]);
			u=par[u][i];
		}
	}
	if(u==v){
		res=merge(res,vec[u]);
	}
	else{
		fd(i,19,0){
			if(par[u][i]!=par[v][i]){
				res=merge(res,ans[u][i]);
				res=merge(res,ans[v][i]);
				u=par[u][i];
				v=par[v][i];
			}
		}
		res=merge(res,vec[par[u][0]]);
		res=merge(res,vec[u]);
		res=merge(res,vec[v]);
	}
	cout<<min((int)res.size(),a)<<" ";
	rep(i,min((int )res.size(),a)){
		cout<<res[i]+1<<" ";
	}
	cout<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	int m,q,i,u,v,a,j,c;
	cin>>n>>m>>q;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans.resize(n);
	rep(i,n){
		ans[i].resize(21);
	}

	rep(i,m){
		cin>>c;
		c--;
		vec[c].pb(i);
	}
	rep(i,n){
		sort(all(vec[i]));
		rep(j,min(10,(int)vec[i].size())){
			ve.pb(vec[i][j]);
		}
		vec[i]=ve;
		ve.clear();
	}
		dfs(0,-1,0);
	precomp();
	rep(i,q){
		cin>>u>>v>>a;
		u--;
		v--;
		compute(u,v,a);
	}
} 
	