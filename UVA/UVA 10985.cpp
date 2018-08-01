/*
	Idea:  For every pair of vertices l and r lets find the number of edges on
		   paths between l to r such that the length of this path is equal to the
		   shortest path length between l to r.
		   So, the answer is maximum of all above calculated number of edges for all l and r.
		   For this,
		   -Initially we compute every pair shortest path using bfs from each vertex.
		   -Then for every pair l and r,we do similar to bfs,push pair(d[l][r],r) into a queue.
		   -for all adjacent vertices(v) of r,push all those vertices such that d[l][v]=d[l][r]-1,and count this r->v edge.
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
queue<int>q;
queue<pii>q1;
set<int>se;
vector<vii>adj(125);
int vis[125],d[125][125];
int main(){
	std::ios::sync_with_stdio(false);
 	int t,t1;
 	cin>>t;
 	t1=t;
 	while(t--){
 		int n,m,i,j,k,val,p,ans=0,a,b;

 		pii p1;
 		
 		cin>>n>>m;
 		rep(i,n){
 			adj[i].clear();
 		}
 		rep(i,m){
 			cin>>a>>b;
 			adj[a].pb(mp(b,i));
 			adj[b].pb(mp(a,i));
 		}
 		rep(i,n){
 			rep(j,n){
 				d[i][j]=inf;
 			}
 		}
 		rep(i,n){
 			d[i][i]=0;
 			q.push(i);
 			rep(k,n){
				vis[k]=0;
			}
			vis[i]=1;
 			while(!q.empty()){
 				p=q.front();
 				q.pop();
 				rep(j,adj[p].size()){
 					if(vis[adj[p][j].ff]==0){
 						vis[adj[p][j].ff]=1;
 						d[i][adj[p][j].ff]=d[i][p]+1;
 						q.push(adj[p][j].ff);
 					}
 				}
 			}
 		}
 		ans=0;
 		rep(i,n){
 			rep(j,n){
 				if(d[i][j]!=inf&&i!=j){
 					se.clear();
 					rep(k,n){
 						vis[k]=0;
 					}
 					vis[j]=1;
 					q1.push(mp(d[i][j],j));
 					while(!q1.empty()){
 						p1=q1.front();
 						q1.pop();
 						val=p1.ff;
 						rep(k,adj[p1.ss].size()){
 							if(d[i][adj[p1.ss][k].ff]==val-1){
 								se.insert(adj[p1.ss][k].ss);
 								if(vis[adj[p1.ss][k].ff]==0){
 									vis[adj[p1.ss][k].ff]=1;
 									q1.push(mp(val-1,adj[p1.ss][k].ff));
 								}
 							}

 						}
 					}
 					ans=max(ans,(int)se.size());
 				}
 			}
 		}
 		cout<<"Case #"<<t1-t<<": ";
 		cout<<ans<<endl;
 	}	
} 
	