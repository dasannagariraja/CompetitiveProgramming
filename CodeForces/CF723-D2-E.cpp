/*
	Idea:http://codeforces.com/blog/entry/47502
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
stack<int>st;
int cnt[205],vis[205],mark[100005];
vector<vii>adj(205);
vector<set<int> >has(205);
vi ans;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m,i,prev,u,v,p,fl=0;
		cin>>n>>m; 
		ans.clear();
		rep(i,n+1){
			cnt[i]=0;
			vis[i]=0;
			adj[i].clear();
			has[i].clear();
		}
		rep(i,100001){
			mark[i]=0;
		}
		rep(i,m){
			cin>>u>>v;
			adj[u].pb(mp(v,i));
			adj[v].pb(mp(u,i));
			has[u].insert(v);
			has[v].insert(u);
			cnt[u]++;
			cnt[v]++;
		}
		prev=-1;
		int res=n;
		rep(i,n+1){
			if(cnt[i]%2){
				if(prev!=-1){
					adj[prev].pb(mp(i,m));
					adj[i].pb(mp(prev,m++));
					prev=-1;
				}
				else{
					prev=i;
				}
				res--; 
			}
			cnt[i]=0;
		}
		cout<<res<<endl;
		rep(i,n+1){
			if(vis[i]==0){
				st.push(i);

				while(!st.empty()){
					p=st.top();
					vis[p]=1;
					fl=0;
					while(cnt[p]<adj[p].size()){
						if(mark[adj[p][cnt[p]].ss]){
							cnt[p]++;
							continue;
						}
						else{
							st.push(adj[p][cnt[p]].ff);
							mark[adj[p][cnt[p]].ss]=1;
							cnt[p]++;
							fl=1;
							break;
						}
					}
					if(fl==0){
						ans.push_back(p);
						st.pop();
					}
				}
			}
		}
		rep(i,(int)ans.size()-1){
			if(has[ans[i]].find(ans[i+1])!=has[ans[i]].end()){
				cout<<ans[i]<<" "<<ans[i+1]<<endl;
				has[ans[i]].erase(ans[i+1]);
				has[ans[i+1]].erase(ans[i]);
			}
		}
		//cout<<mark[5]<<endl;
	}	
} 
	