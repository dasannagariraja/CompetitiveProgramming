/*
	Idea: for every subsequence of first half of string,let string formed by these characters
		  be s.and string formed by remaining characters from first half be s1.
		  Now,we need number of ways such that
		  we will be able to divide second half of string into two subsequences such that
		  one of them will be reverse of s,and other will be reverse of s1.	For computing this, 
		  
		  for every subsequence of second half find the hash of that string formed
		  by this subsequence in the order as they appear and  hash of string 
		  formed by remaining elements from second half.Let this values be hash,hash1.
		  Now store count of these pairs. i.e, map[make_pair(hash,hash1)]++;

		  So, required value is sum of map[make_pair(hash(s),hash(s1))] for every subsequence of
		  first half.
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
int n;
string s;
map<pair<ll,ll>,int>mapi;
map<ll,int>mapi1;
int compute(int x){
	string s1="",s2="";
	int i;
	rep(i,n){
		if(x&(1<<i)){
			s1+=s[i+1*n];
		}
		else{
			s2+=s[i+1*n];
		}
	}
	ll hash=0;
	rep(i,s1.length()){
		hash=hash*31LL;
		hash+=s1[i]-'a'+2;
		hash%=mod;
	}
	ll hash1=0;
	rep(i,s2.length()){
		hash1=hash1*31LL;
		hash1+=s2[i]-'a'+2;
		hash1%=mod;
	}
	mapi[mp(hash,hash1)]++;
}
int get(int x){
	int i;
	ll val;
	string s1="",s2="",s3="";
	rep(i,n){
		if(x&(1<<i)){
		 	s1+=s[i];
		}
		else{
			s2+=s[i];
		}
	}
	ll hash=0;
	fd(i,s1.length()-1,0){
		hash=hash*31LL;
		hash+=s1[i]-'a'+2;
		hash%=mod;
	}
	ll hash1=0;
	fd(i,s2.length()-1,0){
		hash1=hash1*31LL;
		hash1+=s2[i]-'a'+2;
		hash1%=mod;
	}
	return mapi[mp(hash1,hash)];
}
int main(){
	std::ios::sync_with_stdio(false);
	ll res=0,i,val;
	cin>>n;
	cin>>s;
	val=(1<<n);
	f(i,1,val-1){
		compute(i);
	}	
	rep(i,s.length()){
		if(s[i]!=s[s.length()-1-i]){
			break;
		}
	}
	if(i==s.length()){
		res+=2;
	}
	f(i,1,val-1){
		res+=get(i);
	}
	cout<<res<<endl;
} 
	