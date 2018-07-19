/*
	Idea: Ternary search for the answer.
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
int n,k;
int x[100005],y[100005];
ll get(int a){
	int i;
	ll val=0;
	vl vec;
	rep(i,n){
		vec.pb(abs(a-x[i])+y[i]);
	}
	sort(all(vec));
	rep(i,k){
		val+=vec[i];
	}
	return val;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll ans,i;
	cin>>n>>k;
	rep(i,n){
		cin>>x[i]>>y[i];
	}	
	ll lo=1;
	ll hi=inf/10;
	while(hi-lo>=3){
		ll mid1=(2LL*lo+hi)/3;
		ll mid2=(2LL*hi+lo)/3; 
		if(get(mid1)<get(mid2)){
			hi=mid2;
		}
		else{
			lo=mid1;
		}
	}
	ans=get(lo);
	//cout<<lo<<" "<<hi<<endl;
	f(i,lo+1,hi+1){
		ans=min(ans,get(i));
	}
	cout<<ans<<endl;
} 
	