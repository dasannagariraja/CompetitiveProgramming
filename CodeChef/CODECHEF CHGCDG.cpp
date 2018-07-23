/*
	Idea: For every prime factor find the maximum power of it which can appear in gcd
		  after applying the operations.
		  This is done using binary search.
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
ll n;
ll a[100005],evn[100005],odd[100005],c[1000005],cnt[1000005];
set<ll>glo;
set<ll>::iterator it;
vl ::iterator it2;
vector<vl>vec(1000005),sec(1000005);
ll get(ll x){
	set<ll>se;
	set<ll>::iterator it1;
	se.clear();
	while(x>1){
		se.insert(c[x]);
		cnt[c[x]]++;
		x/=c[x];
	}
	for(it1=se.begin();it1!=se.end();it1++){
		glo.insert(*it1);
		if(cnt[*it1]%2==0){
			vec[*it1].pb(cnt[*it1]);
		}
		else{
			sec[*it1].pb(cnt[*it1]);
		}
		cnt[*it1]=0;
	}
}
ll check(ll x,ll c1){
	ll i;
	ll val,val1,val2,val3,val4,val5;
	it2=upper_bound(vec[x].begin(),vec[x].end(),c1);
	val=it2-vec[x].begin();
	it2=upper_bound(sec[x].begin(),sec[x].end(),c1);
	val1=it2-sec[x].begin();
	if(val==vec[x].size()){
		val2=0;
	}
	else{
		val2=evn[(ll)vec[x].size()-1];
		if(val>0){
			val2-=evn[val-1];
		}
	}
	if(c1%2==0){
		val2-=c1*((ll)vec[x].size()-val);
	}
	else{
		val2-=(c1+1)*((ll)vec[x].size()-val);
	}
	if(val1 ==sec[x].size()){
		val3=0;
	}
	else{
		val3=odd[(ll)sec[x].size()-1];
		if(val1>0){
			val3-=odd[val1-1];
		}
	}
	if(c1%2==1){
		val3-=c1*((ll)sec[x].size()-val1);
	}
	else{
		val3-=(c1+1)*((ll)sec[x].size()-val1);
	}
	val2+=val3;
	val2/=2;
	val4=0;
	if(val>0){
		val4=evn[val-1];
	}
	val5=0;
	if(val1>0){
		val5=odd[val1-1];
	}
	val4=c1*(val)-val4;
	val5=c1*(val1)-val5;
	val4+=val5;
	val4+=c1*(n-(int)vec[x].size()-(int)sec[x].size());
	if(val2>=val4){
		return 1;
	}
	return 0;
}
ll getmax(ll x){
	ll ans=0;
	ll lo=0;
	ll hi=0;
	if(vec[x].size()!=0){
		hi=vec[x][vec[x].size()-1];
	}
	if(sec[x].size()!=0){
		hi=max(hi,sec[x][sec[x].size()-1]);
	}
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		if(check(x,mid)){
			lo=mid+1;
			ans=mid;
		}
		else{
			hi=mid-1;
		}
	}
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll t,i,j;
	cin>>t;
	for(i=2;i<1000005;i++){
		if(c[i]!=0){
			continue;
		}
		for(j=i;j<=1000005;j+=i){
			if(c[j]==0){
				c[j]=i;
			}
		}
	}
	while(t--){
		cin>>n;
		glo.clear();	
		rep(i,1000005){
			vec[i].clear();
			sec[i].clear();
		}
		rep(i,n){
			cin>>a[i];
			get(a[i]);
		}
		ll ans=1,val;
		for(it=glo.begin();it!=glo.end();it++){
			sort(all(vec[*it]));
			sort(all(sec[*it]));
			for(i=0;i<vec[*it].size();i++){
				evn[i]=i>0?evn[i-1]+vec[*it][i]:vec[*it][i];
			}
			for(i=0;i<sec[*it].size();i++){
				odd[i]=i>0?odd[i-1]+sec[*it][i]:sec[*it][i];
			}
			val=getmax(*it);
			rep(i,val){
				ans*=(*it);
			}
		}
		cout<<ans<<endl;
	}	
} 
	