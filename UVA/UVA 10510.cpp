/*
	Idea: Check if its strongly connected.
		  Find dfs tree,check if the graph has any forward or cross edge.
		  Check if any node has more than one children with a back edge to the ancestor of it.
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
int fl=0;
int vis[10005],par[10005];
vector<vi>adj(10005),adj1(10005);
int tim=0;
int low[10005],disc[10005];
stack<int>st;
int dfs(int u){
	int i;
	vis[u]=1;
	rep(i,adj[u].size()){
		if(!vis[adj[u][i]]){
			dfs(adj[u][i]);
		}
	}
	st.push(u);
}
int dfs1(int u){
	int i;
	vis[u]=1;
	rep(i,adj1[u].size()){
		if(!vis[adj1[u][i]]){
			dfs1(adj1[u][i]);
		}
	}
}
int dfs2(int u){
	int i,cnt=0;
	low[u]=tim;
	disc[u]=tim;
	tim++;
	vis[u]=1;
	rep(i,adj[u].size()){
		if(vis[adj[u][i]]==2){    				//forward or cross edge
			fl=1;
		}
		else if(!vis[adj[u][i]]){
			par[adj[u][i]]=u;
			dfs2(adj[u][i]);
			low[u]=min(low[u],low[adj[u][i]]);
			if(low[adj[u][i]]<disc[u]){
				cnt++;
			}
		}
		else if(par[u]!=adj[u][i]){
			low[u]=min(disc[adj[u][i]],low[u]);
			cnt++;
		}
	}
	if(cnt>=2){
		fl=1;
	}
	vis[u]=2;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m,i,a,b,j,p;
		fl=0;
		cin>>n>>m;
		rep(i,n){
			adj[i].clear();
		}
		rep(i,m){
			cin>>a>>b;
			adj[a].pb(b);
		}
		rep(i,n){
			vis[i]=0;
		}
		dfs(0);
		rep(i,n){
			rep(j,adj[i].size()){
				adj1[j].pb(i);
			}
		}
		p=st.top();
		rep(i,n){
			vis[i]=0;
		}
		dfs1(p);
		while(!st.empty()){
			p=st.top();
			if(vis[p]!=1){
				fl=1;
				break;
			}
			st.pop();
		}
		if(fl){
			cout<<"NO"<<endl;
		}
		else{
			fl=0;
			rep(i,n){
				vis[i]=0;
			}
			dfs2(0);
			if(fl){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
	}
} 
	
