/*
	Idea: Store an array with prefix Xor's,so that Xor of elements from [i...j]
		  				=pre[j]^pre[i-1].
		  Now, use MO's Algorithm, since each update can be done in O(1).
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
struct query{
	int l,r,i;
}q[100005];
int block=300;
bool cmp(query a,query b){
	if(a.l/block!=b.l/block){
		return a.l/block<b.l/block;
	}
 	return a.r<b.r;
}
ll ans=0,curl,curr,cnt[2000005],a[100005],pre[100005],res[100005],k,val;
ll add(ll pos){
	val=(k^pre[pos]);
	ans+=cnt[val];
	cnt[pre[pos]]++;
}
ll remove(ll pos){
	cnt[pre[pos]]--;
	val=(k^pre[pos]);
	ans-=cnt[val];
}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,m,i,l,r;
	cin>>n>>m>>k;
	f(i,1,n+1){
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}	
	rep(i,m){
		cin>>l>>r;
		q[i].l=l;
		q[i].l--;
		q[i].r=r;
		q[i].i=i;
	}
	sort(q,q+m,cmp);
	curl=0;
	curr=0;
	ans=0;
	cnt[0]=1;
	rep(i,m){
		while(curl>q[i].l){
			add(curl-1);
			curl--;
		}
		while(curr<q[i].r){
			add(curr+1);
			curr++;
		}
		while(curl<q[i].l){
			remove(curl);
			curl++;
		}
		while(curr>q[i].r){
			remove(curr);
			curr--;
		}
		res[q[i].i]=ans;
	}
	rep(i,m){
		cout<<res[i]<<endl;
	}
} 
	