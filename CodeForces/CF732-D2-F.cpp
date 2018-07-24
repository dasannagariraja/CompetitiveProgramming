/*
	Idea: Remove all the bridges and find the sizes of remaining connected components
		  The answer is maximum of all these sizes.
		  Edges can be oriented using a dfs,such that every other vertex other than this
		  component will be able to reach atleast one vertex from this component.
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
int tim=0,c=0,vis[400005],low[400005],disc[400005],par[400005],bridge[400005];
pii edg[400005];
vector<vi>adj1(400005);
vector<vii>adj(400005);
int dfs(int u){
	vis[u]=1;
	disc[u]=tim;
	low[u]=tim;
	tim++;
	int i;
	rep(i,adj[u].size()){
		if(vis[adj[u][i].ff]==0){
			par[adj[u][i].ff]=u;
			dfs(adj[u][i].ff);
			low[u]=min(low[u],low[adj[u][i].ff]);
			if(low[adj[u][i].ff]>disc[u]){
				bridge[adj[u][i].ss]=1;
			}
		}
		else if(par[u]!=adj[u][i].ff){
			low[u]=min(low[u],disc[adj[u][i].ff]);
		}
	}
}
int dfs1(int u){
	vis[u]=1;
	c++;
	int i;
	rep(i,adj1[u].size()){
		if(vis[adj1[u][i]]==0){
			dfs1(adj1[u][i]);
		}
	}
}
int dfs2(int u){
	vis[u]=1;
	int i;
	rep(i,adj[u].size()){
		if(vis[adj[u][i].ff]==0){
			edg[adj[u][i].ss].ff=adj[u][i].ff;
			edg[adj[u][i].ss].ss=u;
			dfs2(adj[u][i].ff);
		}
		else if(par[u]!=adj[u][i].ff){
			edg[adj[u][i].ss].ff=u;
			edg[adj[u][i].ss].ss=adj[u][i].ff;
		}
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,a,b,i,id,maxx=0;
	cin>>n>>m;
	rep(i,m){
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(mp(b,i));
		adj[b].pb(mp(a,i));
		edg[i].ff=a;
		edg[i].ss=b;
		//done[i]=0;
	}	
	par[0]=-1;
	dfs(0);
	rep(i,m){
		if(bridge[i]==0){
			adj1[edg[i].ff].pb(edg[i].ss);
			adj1[edg[i].ss].pb(edg[i].ff);
		}
	}
	rep(i,n){
		vis[i]=0;
	}
	rep(i,n){
		if(vis[i]==0){
			c=0;
			dfs1(i);
			if(c>maxx){
				maxx=c;
				id=i;
			}
		}
	}
	rep(i,n){
		vis[i]=0;
	}
	par[id]=-1;
	dfs2(id);
	cout<<maxx<<endl;
	rep(i,m){
		cout<<edg[i].ff+1<<" "<<edg[i].ss+1<<endl;
	}
} 
	