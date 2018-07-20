/*
	Idea: We need all the vertices which have maximum distance from all affected vertices
			less than or equal to d.
		  Do a dfs from any node as root,and find
		  For all i, 
		  			dist[i]=maximum distance from i to all affected vertices in the subtree
		  					 of i.
		  For all i ans j such that j is child of i,
		  			dist1[i][j]=maximum distance from i to all affected vertices in subtree
		  					of i excluding the vertices from subtree of j. 
		  Do another dfs,
		  		 	if,p is parent of i,and d=dist1[p][i],then overall maximum distance from i
		  		 			= max(dist[i],d+1);
					also for all chirldren j of i,
					update dist1[i][j]=max(dist1[i][j],d+1);

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
int ans=0,dist[100005],vis[100005],par[100005],d1[100005],d;
vector<vi>adj(100005),sub(100005);
int dfs(int u,int p){
	int i,maxx=-1*inf;
	vi vec;
	if(vis[u]){
		vec.pb(0);
		dist[u]=0;
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			par[adj[u][i]]=i;
			dfs(adj[u][i],u);
			vec.pb(dist[adj[u][i]]+1);
			maxx=max(maxx,dist[adj[u][i]]+1);
		}
	}
	sort(all(vec));
	dist[u]=max(dist[u],maxx);
	sub[u].resize(adj[u].size());
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			if(dist[adj[u][i]]+1!=dist[u]){
				sub[u][i]=dist[u];
			}
			else{
				if(vec.size()==1){
					sub[u][i]=-1*inf;
				}
				else{
					sub[u][i]=vec[vec.size()-2];
				}
			}
		}
	}
}
int dfs1(int u,int p){
	int i;
	if(p!=-1){
		d1[u]=sub[p][par[u]]+1;
	}
	else{
		d1[u]=-1*inf;
	}
	int val=max(d1[u],dist[u]);
	if(val<=d){
		ans++;
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			sub[u][i]=max(sub[u][i],d1[u]);
			dfs1(adj[u][i],u);
		}
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,a,b,j;
	cin>>n>>m>>d;
	rep(i,m){
		cin>>a;
		a--;
		vis[a]=1;
	}
	rep(i,n-1){
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}	
	rep(i,n){
		dist[i]=-1*inf;
	}
	dfs(0,-1);
	dfs1(0,-1);
	cout<<ans<<endl;
} 
	