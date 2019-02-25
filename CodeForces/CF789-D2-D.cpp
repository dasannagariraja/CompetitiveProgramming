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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;
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
#define int ll

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

//std::ios::sync_with_stdio(false);

int deg[1000005],vis[1000005],gg[1000005];
vector<vi> adj(1000005);
int dfs(int u){
	vis[u]=1;
	int i;
	rep(i,adj[u].size()){
		if(vis[adj[u][i]]!=1){
			dfs(adj[u][i]);
		}
	}
}
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,m,i,u,v,c=0,res=0,val;
	cin>>n>>m;
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
		if(u==v){
			gg[u]++;
			gg[v]++;
			c++;
		}
		else{
			deg[u]++;
			deg[v]++;
		}
	}
	rep(i,n){
		if(deg[i]!=0){
			dfs(i);
			break;
		}
	}
	rep(i,n){
		if((deg[i]+gg[i])!=0&&vis[i]==0){
			break;
		}
	}
	if(i!=n){
		cout<<0<<endl;
	}
	else{
		rep(i,n){
			val=deg[i]*(deg[i]-1)/2;
			res+=val;
		}
		res+=c*(m-1)-(c*(c-1)/2);
		cout<<res<<endl;
	}
	return 0;
} 
	