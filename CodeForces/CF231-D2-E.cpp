//raja1999
/*		Idea:
	 	Answer for number of paths between x and y is simply 2^(number of cycles from x to y).
	 	We can build bridge tree(https://threads-iiith.quora.com/The-Bridge-Tree-of-a-graph)
	 	of given graph,and find number of shrinked cycles on path from x to y in bridge tree using lca.
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
int tim=0,comp=0,disc[100005],low[100005],isbridge[100005],parent[100005],par[100005][21];
queue<int> q[100005];
vector<vii >adj(100005);
vector<vi>tree(100005);
int u[100005],v[100005],lol[100005],ans[100005],lev[100005], arr[100005],vis[100005];
ll power[100005];
int dfs(int u){
	int i;
	disc[u]=tim++;
	low[u]=disc[u];
	vis[u]=1;
	rep(i,adj[u].size()){
		if(vis[adj[u][i].ff]==0){
			parent[adj[u][i].ff]=u;
			dfs(adj[u][i].ff);
			low[u]=min(low[u],low[adj[u][i].ff]);
			if(low[adj[u][i].ff]>disc[u]){
				isbridge[adj[u][i].ss]=1;
			}
		}
		else if(parent[u]!=adj[u][i].ff){
			low[u]=min(low[u],disc[adj[u][i].ff]);
		}
	}
}
int dfs1(int u){
	int cur,c=0,i,p;
	vis[u]=1;
	cur=comp;
	q[comp].push(u);
	while(!q[cur].empty()){
		p=q[cur].front();
		arr[p]=cur;
		c++;
		q[cur].pop();
		rep(i,adj[p].size()){
			if(vis[adj[p][i].ff]){
				continue;
			}
			if(isbridge[adj[p][i].ss]){
				comp++;
				tree[cur].pb(comp);
				tree[comp].pb(cur);
				dfs1(adj[p][i].ff);
			}
			else{
				vis[adj[p][i].ff]=1;
				q[cur].push(adj[p][i].ff);
			}
		}
	}
	if(c>1){
		lol[cur]=1;
	}
}
int dfs2(int u,int p,int prev,int l){
	int i;
	par[u][0]=p;
	lev[u]=l;
	ans[u]=prev+lol[u];
	rep(i,tree[u].size()){
		if(tree[u][i]!=p){
			dfs2(tree[u][i],u,ans[u],l+1);
		}
	}
}
int pre(){
	int i,j;
	f(i,1,20){
		rep(j,comp){
			if(par[j][i-1]==-1){
				par[j][i]=-1;
				continue;
			}
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}
}
int lca(int u,int v){
	if(lev[u]<lev[v]){
		swap(u,v);
	}
	int i;
	fd(i,19,0){
		if(lev[u]-(1<<i)>=lev[v]){
			u=par[u][i];
		}
	}
	if(u==v){
		return u;
	}
	fd(i,19,0){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,a,b,val,l,j;
	cin>>n>>m;
	rep(i,n+1){
		power[i]=i>0?power[i-1]*2LL:1;
		power[i]%=mod;
	}
	rep(i,m){
		cin>>u[i]>>v[i];
		u[i]--;
		v[i]--;
		adj[u[i]].pb(mp(v[i],i));
		adj[v[i]].pb(mp(u[i],i));
	}
	parent[0]=-1;
	dfs(0);	
	rep(i,n){
		vis[i]=0;
	}
	//return 0;
	dfs1(0);
	//rep(i,comp){
		//cout<<i<<endl;
		//rep(j,tree[i].size()){
			//cout<<tree[i][j]<<" ";
		//}
		//cout<<endl;
	//}
	//return 0;
	comp++;
	dfs2(0,-1,0,0);
	pre();
	int k;
	cin>>k;
	while(k--){
		cin>>a>>b;
		a--;
		b--;
		a=arr[a];
		b=arr[b];
		l=lca(a,b);
		val=ans[a]-ans[l];
		val+=ans[b]-ans[l]+lol[l];
		cout<<power[val]<<endl;
	}
} 
	