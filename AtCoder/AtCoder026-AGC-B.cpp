/*
	Idea: http://codeforces.com/blog/entry/60562?#comment-445168
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
map<ll,int>mapi;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d,a1,cnt,val;
		cin>>a>>b>>c>>d;
		if(a<b||d<b){
			cout<<"No"<<endl;
		}
		else{
			if(c>=b-1){
				cout<<"Yes"<<endl;
			}
			else{
				val=b-(a%b);
				if(val%(__gcd(d,b)))
					val/=__gcd(b,d);
				else{
					val/=__gcd(b,d);
					val--;
				}
				c-=a%b;
				//cout<<val<<" "<<endl;
				if(val>c/(__gcd(b,d))||val<0||c<0){
					cout<<"No"<<endl;
				}
				else{
					cout<<"Yes"<<endl;
				}

			}
		}
	}
} 
	