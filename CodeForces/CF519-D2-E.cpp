/*
	Idea: 	if level[a]<level[b] ,just swap(a,b);
	      -if a==b, ans=n.
		  -if dist(a,b) is odd,ans=0.
		  -find the middle point of path of a to b,if this middle point = lca(a,b),
		   		then ans=n-subtreesize[u]-subtreesize[v].
		   		u=left vertex of lca(a,b) on path a->b,v=right vertex of lca(a,b) on path a->b.
		  -if middle point not = lca(a,b), ans= subtreesize[middle point]-subtreesize[u].
		   		u=left vertx to middle point on path a->b.
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
vector<vi>adj(100005);
int par[100005][20],sz[100005],l[100005],n;
int dfs(int u,int p,int lev){
	int i;
	sz[u]=1;
	par[u][0]=p;
	l[u]=lev;
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			dfs(adj[u][i],u,lev+1);
			sz[u]+=sz[adj[u][i]];
		}
	}
	return 0;
}
int pre(){
	int i,j;
	f(i,1,20){
		rep(j,n){
			if(par[j][i-1]==-1){
				par[j][i]=-1;
				continue;
			}
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}
	return 0;
}
int lca(int a,int b){
	if(l[a]<l[b]){
		swap(a,b);
	}
	int i;
	fd(i,19,0){
		if(l[a]-(1<<i)>=l[b]){
			a=par[a][i];
		}
	}
	if(a==b){
		return a;
	}
	fd(i,19,0){
		if(par[a][i]!=par[b][i]){
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
int main(){
	std::ios::sync_with_stdio(false);
	int i,a,b,val,val1,val2,j,m;
	cin>>n;
	rep(i,n-1){
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	cin>>m;
	dfs(0,-1,0);
	pre();
	rep(i,m){
		cin>>a>>b;
		a--;
		b--;
		if(a==b){
			cout<<n<<endl;
			continue;
		}
		val=lca(a,b);
		val1=l[a]-l[val]+l[b]-l[val];
		if(val1%2){
			cout<<0<<endl;
		}
		else if(l[a]==l[b]){
			val1/=2;
			val1--;
			val2=val1;
			fd(j,19,0){
				if((1<<j)<=val1){
					val1-=(1<<j);
					a=par[a][j];
				}
			}
			fd(j,19,0){
				if((1<<j)<=val2){
					val2-=(1<<j);
					b=par[b][j];
				}
			}
			cout<<n-sz[a]-sz[b]<<endl;
		}
		else{
			val1/=2;
			if(l[a]<l[b]){
				swap(a,b);
			}
			val1--;
			fd(j,19,0){
				if((1<<j)<=val1){
					val1-=(1<<j);
					a=par[a][j];
				}
			}
			cout<<sz[par[a][0]]-sz[a]<<endl;
		}
	}
}	 
	