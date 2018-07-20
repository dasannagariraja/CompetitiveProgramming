/*
	Idea: sort all dominoes w.r.t x,
		  Now, if we iterate in reverse order,for ans[i],
		  find id=index of rightmost domino that falls because of i.
		  find the index between [ i+1,id ] which has max x+h-1 value.
		  Let this index be id1, then ans[i]=id-i+ans[id].

		  Complexity: O(nlogn)
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
pii st[500005];
int ans[100005];
vector<pair<int,pii> >vec;
vector<pair<int,pii> >:: iterator it;
int build(int s,int e,int node){
	if(s==e){
		st[node].ff=vec[s].ff+vec[s].ss.ff-1;
		st[node].ss=s;
		return 0;
	}
	int mid=(s+e)/2;
	build(s,mid,2*node);
	build(mid+1,e,2*node+1);
	st[node]=max(st[2*node],st[2*node+1]);
	return 0;
}
pii query(int l,int r,int s,int e,int node){
	if(l>e||r<s){
		pii p;
		p.ff=-1*inf;
		p.ss=0;
		return p;
	}
	if(s==e){
		return st[node];
	}
	int mid=(s+e)/2;
	return max(query(l,r,s,mid,2*node),query(l,r,mid+1,e,2*node+1));
}
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	pair<int,pii>p;
	pii val1;
	int val,i,x,h;
	cin>>n;
	rep(i,n){
		cin>>x>>h;
		vec.pb(mp(x,mp(h,i)));
	}
	sort(all(vec));
	build(0,n-1,1);
	fd(i,vec.size()-1,0){
		p.ff=vec[i].ff+vec[i].ss.ff-1;
		p.ss.ff=inf;
		p.ss.ss=inf;
		it=upper_bound(vec.begin(),vec.end(),p);
		it--;
		val=it-vec.begin();
		if(val==i){
			ans[vec[i].ss.ss]=1;
		}
		else{
			val1=query(i+1,val,0,n-1,1);
			ans[vec[i].ss.ss]=val1.ss-i+ans[vec[val1.ss].ss.ss];
		}
	}
	rep(i,n){
		cout<<ans[i]<<" ";
	}
} 
	