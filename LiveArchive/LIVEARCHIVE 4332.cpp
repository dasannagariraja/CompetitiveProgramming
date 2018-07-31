/*
	Idea: let dp[i] be number of was to build a board of size i
	 	   		 	dp[i]=2*dp[i-1]+2*dp[i-2].
	 	  Therefore,
	 	  		ans[n]=dp[n]*dp[0]+dp[n-1]*dp[1]+......+dp[1]*dp[n-1]+dp[0]*dp[n].
	 	  This can be rewritten as 
	 	  		ans[n]=2*ans[n-1]+2*ans[n-2]+dp[n].
	 	  This can now be solved with matrix exponentiation.
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
#define mod (1000*10+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);
int matmul(int a[4][4],int b[4][4]){
	int c[4][4],i,j,k;	
	rep(i,4){
		rep(j,4){
			c[i][j]=0;
			rep(k,4){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
	rep(i,4){
		rep(j,4){
			a[i][j]=c[i][j];
		}
	}
}
int matpow(int a[4][4],int n){
	int res[4][4],i,j;
	rep(i,4){
		rep(j,4){
			if(i==j){
				res[i][j]=1;
			}
			else{
				res[i][j]=0;
			}
		}
	}
	while(n>0){
		if(n%2){
			matmul(res,a);
		}
		matmul(a,a);
		n/=2;
	}
	rep(i,4){
		rep(j,4){
			a[i][j]=res[i][j];
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	while(1){
		int i,n,j,a[4][4],b[4][4];
		cin>>n;
		if(n==-1){
			return 0;
		}
		if(n==0){
			cout<<1<<endl;
		}
		else if(n==1){
			cout<<4<<endl;
		}
		else{
			rep(i,4){
				rep(j,4){
					a[i][j]=0;
					b[i][j]=0;
				}
			}
			a[0][0]=1;
			a[1][0]=4;
			a[2][0]=2;
			a[3][0]=6;
			b[0][1]=1;
			b[1][0]=2;
			b[1][1]=2;
			b[1][2]=0;
			b[1][3]=1;
			b[2][3]=1;
			b[3][3]=2;
			b[3][2]=2;
			matpow(b,n-1);
			matmul(b,a);
			cout<<b[1][0]<<endl;
		}
	}	
} 
	