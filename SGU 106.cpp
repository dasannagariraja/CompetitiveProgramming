/*
	Idea:
	Check if a=0 or b=0 separately.
	For a!=0 and b!=0,
		find one solution of ax+by=c using extended euclid algorithm.
		other solutions will be of the form (x-k*b,y+k*a),for all k.
		hence,	x1 <= x-k*b <= x2 and y1 <= x+ka  <= y2. From this find the range of k.
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
ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}

ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll a,b,c,x1,x2,y1,y2,ans,minn,maxx,upa,upb,lbb,lba,val;
	cin>>a>>b>>c>>x1>>x2>>y1>>y2;
	if(x1>x2||y1>y2){
		cout<<0<<endl;
		return 0;
	}
	if(a==0&&b==0){
		if(c==0){
			ans=(x2-x1+1)*(y2-y1+1);
			cout<<ans<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}	
	else if(a==0){
		if(c%b!=0){
			cout<<0<<endl;
		}
		else{
			ans=-1*c;
			ans/=b;
			if(ans>=y1&&ans<=y2){
				cout<<x2-x1+1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	else if(b==0){
		if(c%a!=0){
			cout<<0<<endl;
		}
		else{
			ans=-1*c;
			ans/=a;
			if(ans>=x1&&ans<=x2){
				cout<<y2-y1+1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	else{
		val=gcd(abs(a),abs(b));
		c*=-1LL;
		if(c%val!=0){
			cout<<0<<endl;
		}
		else{
			val=c/val;
			ll x,y;
			extend_gcd(abs(a),abs(b),x,y);
			if(a<0){
				x*=-1LL;
			}
			if(b<0){
				y*=-1LL;
			}
			x*=val;
			y*=val;
			upa=(x-x1)/b;
			if(x-x1<0&&(x-x1)%b!=0){
				upa--;
			}
			lba =(x-x2)/b;
			if(x-x2>0&&(x-x2)%b!=0){
				lba++;
			}
			upb=(y2-y)/a;
			if(y2-y<0&&(y2-y)%a!=0){
				upb--;
			}
			lbb=(y1-y)/a;
			if(y1-y>0&&(y1-y)%a!=0){
				lbb++;
			}
			minn=max(lbb,lba);
			maxx=min(upa,upb);
			ans=max(0LL,maxx-minn+1);
			cout<<ans<<endl;
		}

	}
} 
	