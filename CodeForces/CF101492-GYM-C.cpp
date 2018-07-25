/*
	Idea: For every i,we find minimum j such that gcd(a[i],a[j])=1 and j>i and store it as right[i]=j.
		  Now, for every query we can just find min(right[i]) for all i from l to r.
		  If min(right[i])<=r then there exists a pair.
		  For,this we can use segment tree.
		  For finding right[i],we can do binary search on j from i+1 to n,such that number of coprime
		  numbers with a[i] from i+1 to j euqals 1;	
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
vi v;
vii v1;
vector<vi>vec(100005),se(500005);
vi ::iterator it,it1;
int st[2000005],c[1000006],a[100005],rt[100005];
vi get(int x){
	v.clear();
	while(x>1){
		v.pb(c[x]);
		x/=c[x];
	}
	sort(all(v));
	v.resize(unique(v.begin(),v.end())-v.begin());
	return v;
}
int add(int mask,int id){
	int i,res=1;
	rep(i,v.size()){
		if(mask&(1<<i)){
			res*=v[i];
		}
	}
	se[res].pb(id);
}
pii gen(int mask,int id){
	int i,res=1,c=0;
	rep(i,vec[id].size()){
		if(mask&(1<<i)){
			res*=vec[id][i];
			c++;
		}
	}
	return make_pair(res,c%2);
}
int check(int pos,int st){
	int i,ans=0,val;
	rep(i,v1.size()){
		it=upper_bound(se[v1[i].ff].begin(),se[v1[i].ff].end(),st);
		it1=upper_bound(se[v1[i].ff].begin(),se[v1[i].ff].end(),pos);
		if(it1!=se[v1[i].ff].begin()){
			val=(it1-it);
			if(val>=0){
				if(v1[i].ss==0){
					ans-=val;
				}
				else{
					ans+=val;
				}
			}
		}
	}
 	return pos-st-ans;
}
int build(int s,int e,int node){
	if(s==e){
		st[node]=rt[s];
		return 0;
	}
	int mid=(s+e)/2;
	build(s,mid,2*node);
	build(mid+1,e,2*node+1);
	st[node]=min(st[2*node],st[2*node+1]);
	return 0;
}
int query(int s,int e,int l,int r,int node){
	if(l>e||r<s){
		return inf;
	}
	if(l<=s&&r>=e){
		return st[node];

	}
	int mid=(s+e)/2;
	return min(query(s,mid,l,r,2*node),query(mid+1,e,l,r,2*node+1));
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j,k,val1,l,r,lo,hi;
	pii val;
	for(i=2;i<=1000005;i++){
		if(c[i]!=0){
			continue;
		}
		for(j=i;j<=1000005;j+=i){
			if(c[j]==0){
				c[j]=i;
			}
		}
	}
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
		vec[i]=get(a[i]);
		j=(1<<vec[i].size());
		f(k,1,j){
			add(k,i);
		}
	}	
	int ans;
	rep(i,n){
		lo=i+1;
		hi=n-1;
		ans=n;
		v1.clear();
		j=(1<<vec[i].size());
		f(k,1,j){
			val=gen(k,i);
			v1.pb(val);
		}
		while(lo<=hi){
			int mid=(lo+hi)/2;
			val1=check(mid,i);
			if(val1>=1){
				hi=mid-1;
				ans=mid;
			}
			else{
				lo=mid+1;
			}
		}	
		rt[i]=ans;
	}
	build(0,n-1,1);
	rep(i,m){
		cin>>l>>r;
		l--;
		r--;
		val1=query(0,n-1,l,r,1);
		if(val1<=r){
			cout<<"S"<<endl;
		}
		else{
			cout<<"N"<<endl;
		}
	}
} 
	