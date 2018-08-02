/*
	Idea:https://github.com/miguelAlessandro/CompetitiveProgramming/blob/master/UVA/11090.cpp
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
double dis[60];
vector<vi>adj(60),adj1(60);
vector<vector<double> >wt(60),wt1(60);
int n;
int checknegcycle(int s){
	int i,j,k;
	rep(i,n+1){
		dis[i]=inf;
	}
	dis[s]=0;
	rep(i,n){
		rep(j,n+1){
			rep(k,adj1[j].size()){
				dis[adj1[j][k]]=min(dis[adj1[j][k]],dis[j]+wt1[j][k]);
			}
		}
	}
	rep(j,n+1){
		rep(k,adj1[j].size()){
			if(dis[adj1[j][k]]>dis[j]+wt1[j][k]){
				return 1;
			}
		}
	}
	return 0;
}

int check(double mid){
	int i,j;
	rep(i,n+1){
		adj1[i]=adj[i];
		wt1[i]=wt[i];
		rep(j,adj1[i].size()){
			wt1[i][j]-=mid;
		}
	}
	if(checknegcycle(1)){
		return 1;
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t,t1,t2;
	cin>>t;
	t1=t;
	while(t--){
		int m,i,j,a,b;
		double c,lo,hi,mid,ans;
		cin>>n>>m;
		rep(i,n+1){
			adj[i].clear();
			wt[i].clear();
		}
		rep(i,m){
			cin>>a>>b>>c;
			adj[a].pb(b);
			wt[a].pb(c);
		}
		lo=0;
		hi=10000006;
		t2=100;
		ans=-1;
		while(t2--){
			mid=(lo+hi)/2.0;
			if(check(mid)){
				hi=mid;
				ans=mid;
				// if(mid==2){
				// 	cout<<"hi"<<endl;
				// }
			}
			else{
				lo=mid;
			}
		}
		//cout<<check(2.5)<<endl;
		cout<<"Case #"<<t1-t<<": ";
		cout.precision(2);
		if(ans==-1){
			cout<<"No cycle found."<<endl;
		}
		else{
			//cout<<ans<<" "<<hi<<endl;
			cout<<fixed<<ans<<endl;
		}
	}	
} 
	