/*
	Idea: Count the number of lists formed by permutation of given words that are lexicograpically
		  smaller than original list.
		  This count = sum(ans[i]) , for all i from 0 to n-1.
		  ans[i]=number of lists with permutations of given words such that all the words till i-1 
		  are same as in given list,and i th word is lexicographically smaller than i th word in given list.
*/
//raja1999
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
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
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
string fact[1005];
map<string,int>mapi;
ordered_set se;
map<string,int>::iterator it;
//Convert number to string
string tostring(int x){
	if(x==0){
		return "0";
	}
	vi vec;
	int i;
	while(x>0){
		vec.pb(x%10);
		x/=10;
	}
	string str="";
	rep(i,vec.size()){
		str+="a";
	}
	fd(i,vec.size()-1,0){
		str[vec.size()-1-i]=vec[i]+'0';
	}
	return str;
}
//Multiply two strings
string mul(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
 
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";
 
    // generate the result string
    string s = "";
    while (i >= 0){
        s +=tostring(result[i--]);
    }
 
    return s;
}
//Add two strings
string add(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
string s[1005];
int main(){
	std::ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	rep(i,1005){
		fact[i]=i>0?mul(fact[i-1],tostring(i)):"1";
	}
	while(t--){
		ll n,c;
		string ans="0";
		mapi.clear();
		se.clear();
		cin>>n;
		rep(i,n){
			cin>>s[i];
			mapi[s[i]]=1;
		}
		c=0;
		for(it=mapi.begin();it!=mapi.end();it++){
			it->ss=c++;
		}
		rep(i,n){
			se.insert(mapi[s[i]]);
		}
		string val;
		rep(i,n){
			val="0";
			int val1=se.order_of_key(mapi[s[i]]);
			if(val1!=0){
				val=mul(fact[n-i-1],tostring(val1));
			}
			ans=add(ans,val);
			se.erase(mapi[s[i]]);
		}
		cout<<add(ans,"1")<<endl;
	}
} 
	