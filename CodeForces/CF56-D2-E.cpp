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
pii st[100005][20];
int n;
int ans[100005];
vector<pair<int,pii> >vec;
vector<pair<int,pii> >:: iterator it;
int pre(){
	pii p,p1;
	int i,j;
	rep(i,n-1){
		p.ff=vec[i].ff+vec[i].ss.ff-1;
		p.ss=i;
		st[i][0]=p;
	}
	p.ss=i;
	p.ff=vec[i].ff+vec[i].ss.ff-1;
	st[i][0]=p;
	f(i,1,20){
		fd(j,n-1,0){
			if(j+(1<<(i))<n){
				st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			}
		}
	}
}
pii query(int l,int r){
	int i;
	pii maxx;
	maxx.ff=-1*inf;
	fd(i,19,0){
		if(l+(1<<i)<=r){
			maxx=max(maxx,st[l][i]);
			l=l+(1<<i);
		}
	}
	maxx=max(maxx,st[l][0]);
	return maxx;
}
int main(){
	std::ios::sync_with_stdio(false);
	pair<int,pii>p;
	pii val1;
	int val,i,x,h;
	cin>>n;
	rep(i,n){
		cin>>x>>h;
		vec.pb(mp(x,mp(h,i)));
	}
	sort(all(vec));
	pre();
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
			val1=query(i+1,val);
			ans[vec[i].ss.ss]=val1.ss-i+ans[vec[val1.ss].ss.ss];
		}
	}
	rep(i,n){
		cout<<ans[i]<<" ";
	}
} 
	
