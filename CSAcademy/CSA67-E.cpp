/*
	Idea: https://csacademy.com/contest/round-67/task/hamming-distances/solution/
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
int ans[20],cnt[256][256][9],a[200005],prec[256];
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j,k,val,val1,i1;
	rep(i,256){
		rep(j,8){
			if(i&(1<<j)){
				prec[i]++;
			}
		}
	}
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		rep(j,m+1){
			ans[j]=0;
		}
		val=0;
		val1=0;
		rep(i1,16){
			if(a[i]&(1<<i1)){
				if(i1<8){
					val1+=(1<<i1);
				}
				else{
					val+=(1<<(i1-8));
				}
			}
		}
		rep(j,256){
			rep(k,9){
				ans[k+prec[j^val]]+=cnt[val1][j][k];
			}
		}
		rep(j,m+1){
			cout<<ans[j]<<" ";
		}
		cout<<endl;
		rep(j,256){
			cnt[j][val][prec[j^val1]]++;
		}
	}
} 
	