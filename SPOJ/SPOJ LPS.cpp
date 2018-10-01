//raja1999
/*	 		Idea:
			For every index i from 0 to s.length(),lets find the maximum length of
			palindrome substring in s,which has odd length and its middle element is s[i].
			Similarly we will also find the maximum length of palindromic substring in s which
			have even length and middle elements as s[i] and s[i+1](If s[i]==s[i+1]).
			Ans is maximum these lengths for every index i.
			For finding this maximum length palindromic substring with centre at i,we can do binary 
			search with hashes.

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
ll hashi[100005],power[100005],hsh[100005];
int main(){
	std::ios::sync_with_stdio(false);
	ll n,prev=0,val,val1,i,len,lo,hi,ans,res=0;
	cin>>n;
	string s;
	cin>>s;	
	rep(i,s.length()){
		hashi[i]=prev*31LL+s[i]-'a';
		hashi[i]%=mod;
		prev=hashi[i];
	}
	prev=0;
	fd(i,s.length()-1,0){
		hsh[i]=prev*31LL+s[i]-'a';
		hsh[i]%=mod;
		prev=hsh[i];
	}
	rep(i,s.length()){
		power[i]=i>0?power[i-1]*31LL:1;
		power[i]%=mod;
	}
	rep(i,s.length()){
		if(i!=s.length()-1&&s[i]==s[i+1]){
			len=min(i+1,(int)s.length()-i-1);
			lo=1;
			hi=len;
			ans=0;
			while(lo<=hi){
				int mid=(lo+hi)/2;
				val=0;
				if(i-mid+1!=0){
					val=hashi[i-mid];
				}
				val1=hsh[i+mid+1];
				val=hashi[i]-val*power[mid];
				val1=hsh[i+1]-val1*power[mid];
				val%=mod;
				val1%=mod;
				val+=mod;
				val1+=mod;
				if(val==val1){
					lo=mid+1;
					ans=mid;
				}
				else{
					hi=mid-1;
				}
			}
			//cout<<ans<<endl;
			res=max(res,2*ans);
		}
		len=min((int)s.length()-1-i,i);
		ans=0;
		lo=1;
		hi=len;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			val=0;
			if(i-mid!=0){
				val=hashi[i-mid-1];
			}
			val1=hsh[i+mid+1];
			val=hashi[i-1]-val*power[mid];
			val1=hsh[i+1]-val1*power[mid];
			val%=mod;
			val1%=mod;
			val+=mod;
			val1+=mod;
			if(val==val1){
				lo=mid+1;
				ans=mid;
			}
			else{
				hi=mid-1;
			}
		}
		res=max(res,2*ans+1);
	}
	cout<<res<<endl;
} 
	