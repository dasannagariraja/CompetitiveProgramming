//raja1999

/*
	Idea: take each digit in s and count number of ways in which this digit contributes in
		  10^0 position + in 10^1 position + in 10^2 position , ... etc for all positions
		  and add x*10^i*(no.of ways) to the answer.
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
ll inv[100003],mult[100003],invmult[100003],a[100003],coun[100003];
ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}

ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}
ll combination(ll n,ll r){
	if(r==0)
		return 1;
	if(n<r)
		return 0;
	ll ans=1;
	ans*=mult[n];
	ans%=mod;
	ans*=invmult[r];
	ans%=mod;
	ans*=invmult[n-r];
	ans%=mod;
	return ans;
}

ll initcombi(){
	int i;
	f(i,1,100001){
		ll x,y;
		ll val=extend_gcd(mod,i,x,y);
		if(y>0)
			inv[i]=y%mod;
		else{
				inv[i]=(y+mod)%mod;
		}
	}
	mult[0]=1;
	f(i,1,100001){
		mult[i]=mult[i-1]*i;
		mult[i]%=mod;
	}
	invmult[0]=1;
	f(i,1,100001){
		invmult[i]=invmult[i-1]*inv[i];
		invmult[i]%=mod;
	}
	return 0;
}


// do initcombi(); 
int lol[100005],val[100005],pre[100005];
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,k,i,gg,haha,res=0;
	cin>>n>>k;
	string s;
	cin>>s;
	initcombi();
	rep(i,n){
		lol[i]=i>0?lol[i-1]*10LL:1;
		lol[i]%=mod;
	}
	fd(i,n-2,k-1){
		val[i]=lol[n-2-i]*combination(i,k-1);
		val[i]%=mod;
	}
	pre[n-1]=0;
	fd(i,n-2,k-1){
		pre[i]=pre[i+1]+val[i];
		pre[i]%=mod;
	}
	//return 0;
	rep(i,n){
		gg=s[i]-'0';
		haha=pre[max(k-1,i)];
		if(i>k-1){
			haha+=lol[n-i-1]*combination(i,k);
			haha%=mod;
		}
		gg*=haha;
		gg%=mod;
		res+=gg;
		res%=mod;
	}
	cout<<res<<endl;
	return 0;
} 
	