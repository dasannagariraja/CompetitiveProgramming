/* 
	Idea:divide the array into  minimum number of ranges,such that each range contains
	 	 same values.For each range add size/2 to the answer,i.e just change the alternate
	 	 positions values. 
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
int a[1000];
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,ans=0,c,prev;
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}	
	c=1;
	prev=a[0];
	f(i,1,n){
		if(a[i]!=prev){
			ans+=c/2;
			prev=a[i];
			c=1;
		}
		else{
			c++;
		}
	}
	ans+=c/2;
	cout<<ans<<endl;

} 
	