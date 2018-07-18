/*
	Idea: dp[i][j][k][mask] is the number of ways to build j roads using [i to n-1]
		  vertices,mask represents the parity of number of incident edges to vertices [i-k to i]
		  till now,and now we are trying to add an edge to i-k-1 fron i.
		  So, dp[i][j][k][mask]=dp[i][j][k+1][mask]; If we are not adding an edge i to i-k-1.
		  	  dp[i][j][k][mask]+=dp[i][j+1][k][mask^(1<<(k+1))^(1<<0)]; If we add and edge between
		  	  i to i-k-1.
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

ll dp[35][35][9][(1<<9)];
class DengklekBuildingRoads{
	public:
		int numWays(int N, int M, int K){

			ll val,val1,i,j,k,k1;
			dp[N][M][0][0]=1;
			val=(1<<(K+1));
			fd(i,N-1,0){
				fd(j,M,0){
					rep(k,val){
						if(!(k&(1<<K))){
							dp[i][j][K][k]=dp[i+1][j][0][k<<1];
						}
					}
					fd(k,K-1,0){
						rep(k1,val){
							val1=dp[i][j][k+1][k1];
							if(i-k-1>=0&&j<=M){
								val1+=dp[i][j+1][k][k1^(1<<(k+1))^(1<<0)];
							}
							val1%=mod;
							dp[i][j][k][k1]=val1;
						}
					}
				}
			}
			return dp[0][0][0][0];
		}
		

};
