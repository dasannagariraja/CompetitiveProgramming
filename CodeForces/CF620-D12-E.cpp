/*
	Idea:
		  	-Do Euler tour and store the intime and outtime of the vertices.
		  	-For each colour maintain a segment tree,where each node in segment tree stores
		  	 number of vertices of that colour in between start to end of that segment in the
		  	 euler tour.
			-query 1: Range update of inv] to out[v] in colour c to 1.	In remaining colours to 0.
   		 	-query 2:for every colour calculate range sum from in[v] to out[v].

   		 	Result: Memory Limit Exceeded.
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
int c[400005],in[400005],out[400005],st[61][1600005],lazy[61][1600005],arr[400005];
vector<vi>adj(400005);
int build(int id,int s,int e,int node){
	if(s==e){
		if(c[arr[s]]==id){
			st[id][node]=1;
		}
		else{
			st[id][node]=0;
		}
		return 0;
	}
	int mid=(s+e)/2;
	build(id,s,mid,2*node);
	build(id,mid+1,e,2*node+1);
	st[id][node]=st[id][2*node]+st[id][2*node+1];
	return 0;
}
int rangeupd(int id,int s,int e,int l,int r,int node,int val){
	if(lazy[id][node]!=-1){
		st[id][node]=lazy[id][node]*(e-s+1);
		if(s!=e){
			lazy[id][2*node]=lazy[id][node];
			lazy[id][2*node+1]=lazy[id][node];
		}
		lazy[id][node]=-1;
	}
	if(l>e||r<s){
		return 0;
	}
	if(s>=l&&e<=r){
		st[id][node]=val*(e-s+1);
		lazy[id][node]=-1;
		if(s!=e){
			lazy[id][2*node]=val;
			lazy[id][2*node+1]=val;
		}
		return 0;
	}
	int mid=(s+e)/2;
	rangeupd(id,s,mid,l,r,2*node,val);
	rangeupd(id,mid+1,e,l,r,2*node+1,val);
	st[id][node]=st[id][2*node]+st[id][2*node+1];
	return 0;
}
int query(int id,int s,int e,int l,int r,int node){
	if(l>e||r<s){
		return 0;
	}
	if(lazy[id][node]!=-1){
		st[id][node]=lazy[id][node]*(e-s+1);
		if(s!=e){
			lazy[id][2*node]=lazy[id][node];
			lazy[id][2*node+1]=lazy[id][node];
		}
		lazy[id][node]=-1;
	}
	if(l<=s&&r>=e){
		return st[id][node];
	}
	int mid=(s+e)/2;
	return query(id,s,mid,l,r,2*node)+query(id,mid+1,e,l,r,2*node+1);
}
int tim=0;
int dfs(int u,int p){
	in[u]=tim;
	arr[tim++]=u;
	int i;
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
	int n,m,i,j,a,b,typ,ans;
	cin>>n>>m;
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
	rep(i,61){
		build(i,0,n-1,1);
	}
	rep(i,61){
		rep(j,1600005){
			lazy[i][j]=-1;
		}
	}
	rep(j,m){
		cin>>typ;
		if(typ==1){
			cin>>a>>b;
			a--;
			rep(i,61){
				if(i!=b){
					rangeupd(i,0,n-1,in[a],out[a]-1,1,0);
				}
				else{
					rangeupd(i,0,n-1,in[a],out[a]-1,1,1);
				}
			}
		}
		else{
			cin>>a;
			a--;
			ans=0;
			rep(i,61){
				if(query(i,0,n-1,in[a],out[a]-1,1)>0){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
} 
	