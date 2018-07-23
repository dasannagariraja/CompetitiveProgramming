/*
	Idea: similar to http://codeforces.com/blog/entry/6073 ,
	 	 I have checked for every pair of columns instead of every pair of rows.
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
vector<vi>vec(30);
char a[405][405];
ll sum[405][405];
ll s[405];
int main(){
	std::ios::sync_with_stdio(false);
	ll n,m,k,i,j,l,sl,fr,val;
	ll ans=0;
	freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	cin>>n>>m>>k;	
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
			sum[i][j]=j>0?sum[i][j-1]:0;
			if(a[i][j]=='a'){
				sum[i][j]++;
			}
		}
	}
	rep(i,m){
		f(j,i+1,m){
			rep(l,n){
				s[l]=l>0?s[l-1]+sum[l][j]:sum[l][j];
				if(i>0){
					s[l]-=sum[l][i-1];
				}
			}
			rep(l,26){
				vec[l].clear();
			}
			rep(l,n){
				if(a[l][i]==a[l][j]){
					vec[a[l][i]-'a'].pb(l);
				}
			}
			rep(l,26){
				sl=0;
				fr=0;
				while(fr<vec[l].size()){
					while(sl<fr){
						val=s[vec[l][fr]];
						if(vec[l][sl]!=0){
							val-=s[vec[l][sl]-1];
						}
						if(val>k){
							sl++;
						}
						else{
							break;
						}

					}
					ans+=fr-sl;
					fr++;
				}
			}
		}
	}
	cout<<ans<<endl;
} 
	