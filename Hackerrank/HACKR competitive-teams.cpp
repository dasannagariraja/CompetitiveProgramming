/*
	Idea:
		maintain counts of the sizes of teams present.
		query 1: merge x,y using dsu and update the counts accordingly.
		query 2: if c>=n, ans=0
			else if c=0,ans=all possible pairs.
			else 
			for each distinct size value i,calculate number of pairs possible
					=count[i]*(sum of count[j]),such that j>=i+c.
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
ll cnt[100005],par[100005],sz[100005];
set<int>se;
ll val1;
set<int>::iterator it,it1;
int root(int u){
	if(par[u]<0){
		return u;
	}
	return par[u]=root(par[u]);
}
int merge(int u,int v){
	u=root(u);
	v=root(v);
	if(u==v){
		return 0;
	}
	val1--;
	if(sz[u]<sz[v]){
		cnt[sz[u]]--;
		cnt[sz[v]]--;
		if(cnt[sz[u]]==0){
			se.erase(sz[u]);
		}
		if(cnt[sz[v]]==0){
			se.erase(sz[v]);
		}
		par[u]=v;
		sz[v]+=sz[u];
		cnt[sz[v]]++;
		se.insert(sz[v]);
	}
	else{
		cnt[sz[u]]--;
		cnt[sz[v]]--;
		if(cnt[sz[u]]==0){
			se.erase(sz[u]);
		}
		if(cnt[sz[v]]==0){
			se.erase(sz[v]);
		}
		par[v]=u;
		sz[u]+=sz[v];
		cnt[sz[u]]++;
		se.insert(sz[u]);
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,q,i,typ,c,x,y,ans=0,val=0,j;
	cin>>n>>q;
	se.insert(1);
	cnt[1]=n;
	val1=n;
	rep(i,n){
		par[i]=-1;
		sz[i]=1;
	}
	rep(i,q){
		cin>>typ;
		if(typ==1){
			cin>>x>>y;
			x--;
			y--;
			merge(x,y);
		}
		else{
			cin>>c;
			if(c==0){
				cout<<(val1)*(val1-1)/2<<endl;
				continue;
			}
			if(c>=n){
				cout<<0<<endl;
			}
			else{
				it=se.begin();
				it1=se.end();
				it1--;
				ans=0;
				val=0;
				while(it1!=se.begin()&&*it1>=*it+c){
					val+=cnt[*it1];
					it1--;
				}
				it1++;
				ans=val*cnt[*it];
				while(1){
					it++;
					if(it1==se.end()||it==se.end()){
						break;
					}
					while(it1!=se.end()&&*it1<*it+c){
						val-=cnt[*it1];
						it1++;
					}
					ans+=val*cnt[*it];
				}
				cout<<ans<<endl;
			}
		}
	}
} 
	
