/*
	Idea:
		  	-Do Euler tour and store the intime and outtime of the vertices.
		  	-Since there are 60 colours,we can represent a set of distinct colours using 
	 		 some integer between 1 and (1<<60).
	 		-We maintain a segment tree,each node stores the mask of distinct colours present
	 		 in that segment.
	 		-query 1 : Just change the range in[v] to out[v] in segment tree to (1<<c).
	 		-query 2 : find the mask of colours in in[v] to out[v], and find number of 1's in that.
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
ll c[400005],in[400005],out[400005],st[1600005],lazy[1600005],arr[400005];
vector<vi>adj(400005);
ll build(ll s,ll e,ll node){
	if(s==e){

		st[node]=(1LL<<c[arr[s]]);
		return 0;
	}
	ll mid=(s+e)/2;
	build(s,mid,2*node);
	build(mid+1,e,2*node+1);
	st[node]=(st[2*node]|st[2*node+1]);
	return 0;
}
ll rangeupd(ll s,ll e,ll node,ll l,ll r,ll val){
	if(lazy[node]!=-1){
		st[node]=(1LL<<(lazy[node]));
		if(s!=e){
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node]=-1;
	}
	if(l>e||r<s){
		return 0;
	}
	if(s>=l&&e<=r){
		st[node]=(1LL<<val);
		lazy[node]=-1;
		if(s!=e){
			lazy[2*node]=val;
			lazy[2*node+1]=val;
		}
		return 0;
	}
	ll mid=(s+e)/2;
	rangeupd(s,mid,2*node,l,r,val);
	rangeupd(mid+1,e,2*node+1,l,r,val);
	st[node]=(st[2*node]|st[2*node+1]);
	return 0;
}
ll query(ll s,ll e,ll node,ll l,ll r){
	//cout<<l<<" "<<r<<endl;
	if(l>e||r<s){
		return 0;
	}
	if(lazy[node]!=-1){
		st[node]=(1LL<<(lazy[node]));
		if(s!=e){
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node]=-1;
	}
	if(l<=s&&r>=e){
		//cout<<arr[s]<<" "<<s<<" "<<e<<" "<<l<<" "<<r<<endl;
		return st[node];
	}
	ll mid=(s+e)/2;
	return (query(s,mid,2*node,l,r))|(query(mid+1,e,2*node+1,l,r));
}
ll tim=0;
ll dfs(ll u,ll p){
	in[u]=tim;
	arr[tim++]=u;
	ll i;
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			dfs(adj[u][i],u);
		}
	}
	out[u]=tim;
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,m,i,j,a,b,typ,ans,val;
	cin>>n>>m;
	//cout<<(1LL<<60)<<endl;
	rep(i,n){
		cin>>c[i];
	}
	rep(i,n-1){
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,-1);
	build(0,n-1,1);
	rep(j,1600005){
		lazy[j]=-1;
	}
	//cout<<st[1]<<endl;
	rep(j,m){
		cin>>typ;
		if(typ==1){
			cin>>a>>b;
			a--;
			rangeupd(0,n-1,1,in[a],out[a]-1,b);
		}
		else{
			cin>>a;
			a--;
			ans=0;
			val=query(0,n-1,1,in[a],out[a]-1);
			//cout<<val<<endl;
			rep(i,61){
				if(val&(1LL<<i)){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
} 
	
