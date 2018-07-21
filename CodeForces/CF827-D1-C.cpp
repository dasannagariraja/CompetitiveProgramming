/*
	Idea:
			-since we are repeating the string c,each character occurs at interval of length.
			-so for each character c[i],we find number of its occurences in s,such that they 
			 are at interval of length of c,starting from l+i.
			-this can be done by maintaing arr[id][len][i%len][i],id is for each character 'A'
			 or 'G' or 'T' or 'C', 1<=len<=10 ,1<=i<=s.length().
			-arr[id][len][i%len][i]=1,if map[s[i]]=id.
			-since we need range sums on these arrays,it can be done using binary indexed tree. 

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
int bit[4][11][10][100015],n,q;
map<char,int>mapi;
int query(int id,int len,int m,int pos){
	int sum=0;
	while(pos>0){
		sum+=bit[id][len][m][pos];
		pos-=pos&(-pos);
	}
	return sum;
}
int update(int id,int len,int m, int pos,int val){
	while(pos<n+10){
		bit[id][len][m][pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	string s;
	string s1;
	char b;
	int t,a,c,i,j,ans=0,len;
	cin>>s;
	n=s.length();
	mapi['A']=0;
	mapi['T']=1;
	mapi['G']=2;
	mapi['C']=3;
	rep(i,s.length()){
		f(j,1,11)
			update(mapi[s[i]],j,i%j,i+1,1);
	}
	cin>>q;
	while(q--){
		cin>>t>>a;
		if(t==1){
			cin>>b;
			a--;
			f(j,1,11){
				update(mapi[s[a]],j,a%j,a+1,-1);
			}
			s[a]=b;
			f(j,1,11){
				update(mapi[s[a]],j,a%j,a+1,1);
			}
		}
		else{
			cin>>c>>s1;
			a--;
			c--;
			ans=0;
			len=s1.length();
			rep(i,min(len,c-a+1)){
				int val=query(mapi[s1[i]],len,(a+i)%len,c+1)-query(mapi[s1[i]],len,(a+i)%len,a);
				ans+=val;
			}
			cout<<ans<<endl;
		}
	}
} 
	