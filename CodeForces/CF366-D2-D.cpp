//raja1999

/*
	Idea: since the number of x possible on a path is min(r[i])-max(l[i]) on that path,
		  we can fix an edge e to contribute to the max(l[i]), and find the maximum value of 
		  min(r[i]) that can be obtained among all paths through that edge e,and the condition
		  that l[e] should be max(l[i]).This can be done through dijkstra's.
		  Here we also observe that self loops doesnt matter.

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

int n;
vector<vi>adj(1005),edg(1005);
int d[1005],a[3005],b[3005],l[3005],r[3005];
set<pii>se;
set<pii>::iterator it;
int dijk(int u,int v,int lol){
	int i;
	pii p;
	rep(i,n){
		d[i]=-1;
	}
	rep(i,adj[u].size()){
		if(l[edg[u][i]]<=lol)
			d[adj[u][i]]=max(d[adj[u][i]],r[edg[u][i]]);
	}
	rep(i,n){
		if(i!=u){
			se.insert(mp(d[i],i));
		}
	}
	while(!se.empty()){
		it=se.end();
		it--;
		p=*it;
		se.erase(it);
		rep(i,adj[p.ss].size()){
			if(l[edg[p.ss][i]]<=lol){
				if(d[adj[p.ss][i]]<min(p.ff,r[edg[p.ss][i]])){
					se.erase(mp(d[adj[p.ss][i]],adj[p.ss][i]));
					d[adj[p.ss][i]]=min(p.ff,r[edg[p.ss][i]]);

					se.insert(mp(d[adj[p.ss][i]],adj[p.ss][i]));
				}
			}
		}
	}
	return d[v];

}
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int m,i,maxl,minr,res=0;
	cin>>n>>m;
	rep(i,m){
		cin>>a[i]>>b[i]>>l[i]>>r[i];
		a[i]--;
		b[i]--;
		if(a[i]==b[i]){
			continue;
		}
		adj[a[i]].pb(b[i]);
		adj[b[i]].pb(a[i]);
		edg[a[i]].pb(i);
		edg[b[i]].pb(i);
	}	
	rep(i,m){
		if(a[i]==b[i]){
			continue;
		}
		maxl=l[i];
		minr=r[i];
		minr=min(minr,dijk(a[i],0,maxl));
		minr=min(minr,dijk(b[i],n-1,maxl));
		res=max(res,minr-maxl+1);
	}
	if(res>0){
		cout<<res<<endl;
	}
	else{
		cout<<"Nice work, Dima!"<<endl;
	}
	return 0;
} 
	