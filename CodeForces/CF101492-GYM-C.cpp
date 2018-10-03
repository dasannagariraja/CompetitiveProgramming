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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

pii p;
int vis[500005],low[500005],AP[500005],par[500005][20],disc[500005],ans[500005],res[500005];
int lev[500005],u[500005],v[500005],parent[500005],tim=0;
vector<vi>adj(500005),adj1(500005),tree(500005);
map<int,int>mapi;
int counti=0;
stack<pii>st;
vector< set<int> >vv(500005);
int c=0;
set<int>::iterator it;
void dfs(int u)
{
vis[u]=true;
int  i;
low[u]=disc[u]=(++tim);
int child=0;
  for(i=0;i<adj[u].size();i++)
  {
   int v=adj[u][i];
   if(vis[v]==false)
   {
    child++;
    parent[v]=u;
    st.push(mp(u,v));
    dfs(v);

    low[u]=min(low[u],low[v]);  
    if( (parent[u]!=-1) and ( low[v]>=disc[u] ) ){
        p=st.top();
        while (p.ff != u || p.ss != v) { 
            //cout << st->back().u << "--" << st->back().v << " ";
            vv[counti].insert(p.ff);
            vv[counti].insert(p.ss); 
            st.pop(); 
            p=st.top();
        } 
        vv[counti].insert(p.ff);
        vv[counti].insert(p.ss);
        st.pop();
        counti++; 
        AP[u]=true;
    }
    else if( (parent[u]==-1) and (child>1)){
        p=st.top();
        while (p.ff != u || p.ss != v) { 
            //cout << st->back().u << "--" << st->back().v << " ";
            vv[counti].insert(p.ff);
            vv[counti].insert(p.ss); 
            st.pop(); 
            p=st.top();
        } 
        vv[counti].insert(p.ff);
        vv[counti].insert(p.ss);
        st.pop();
        counti++; 
      AP[u]=true;
    }
   }
   else if(v!=parent[u])
    {low[u]=min(low[u],disc[v]);}
  }

}
vi vec;
int dfs1(int u){
	vis[u]=1;
	mapi[u]=c;
	vec.pb(u);
	if(AP[u]){
		return 0;
	}
	//cout<<u+1<<" ";
	int i;
	rep(i,adj1[u].size()){
		if(!vis[adj1[u][i]]){
			dfs1(adj1[u][i]);
		}
	}
}
int dfs2(int u,int p,int prev,int l){
	par[u][0]=p;
	int i;
	lev[u]=l;
	ans[u]=prev+res[u];
	rep(i,tree[u].size()){
		if(tree[u][i]!=p){
			dfs2(tree[u][i],u,ans[u],l+1);
		}
	}
}
int pre(){
	int i,j;
	f(i,1,20){
		rep(j,c){
			if(par[j][i-1]==-1){
				par[j][i]=-1;
				continue;
			}
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}
}
int lca(int u,int v){
	int i;
	if(lev[u]<lev[v]){
		swap(u,v);
	}
	fd(i,19,0){
		if(lev[u]-(1<<i)>=lev[v]){
			u=par[u][i];
		}
	}
	if(u==v){
		return u;
	}
	fd(i,19,0){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q,m,i,u1,v1,val,l,j;
    cin>>n>>m>>q;
    rep(i,m){
    	cin>>u[i]>>v[i];
    	u[i]--;
    	v[i]--;
    	adj[u[i]].pb(v[i]);
    	adj[v[i]].pb(u[i]);
    }
    int fl=0;
    parent[0]=1;
    dfs(0);
    while (!st.empty()) { 
        //cout << st->back().u << "--" << st->back().v << " ";
        p=st.top();
        fl=1;
        vv[counti].insert(p.ff);
        vv[counti].insert(p.ss); 
        st.pop();
    } 
    if(fl)
        counti++;
    // rep(i,m){
    // 	if(!AP[u[i]]&&!AP[v[i]]){
    // 		adj1[u[i]].pb(v[i]);
    // 		adj1[v[i]].pb(u[i]);
    // 	}

    // }
    rep(i,counti){
        for(it=vv[i].begin();it!=vv[i].end();it++){
            mapi[*it]=i;
            //cout<<*it<<" ";
        }
        //cout<<endl;
    }
    c=i;
    rep(i,n){
        if(AP[i]){
            mapi[i]=c;
            res[c]=1;
            c++;
        }
    }
    rep(i,counti){
        for(it=vv[i].begin();it!=vv[i].end();it++){
            if(AP[*it]){
                tree[mapi[*it]].pb(i);
                tree[i].pb(mapi[*it]);
            }
        }
    }
    // cout<<counti<<endl;
    // rep(i,c){
    //     cout<<tree[i].size()<<endl;
    //     rep(j,tree[i].size()){
    //         cout<<tree[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"AEDSSADASD"<<endl;
    //return 0;
    rep(i,counti){
    	vis[i]=0;
    }
    dfs2(0,-1,0,0);
    pre();
    //return 0;
   // cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    while(q--){
    	cin>>u1>>v1;
    	u1--;
    	v1--;
    	if(u1==v1){
    		cout<<0<<endl;
    		continue;
    	}
    	if(mapi[u1]==mapi[v1]){
    		cout<<1<<endl;
    		continue;
    	}
    	l=lca(mapi[u1],mapi[v1]);
    	//cout<<mapi[u1]<<" "<<mapi[v1]<<" "<<l<<endl;
    	val=ans[mapi[u1]]-ans[l];
    	val+=ans[mapi[v1]]-ans[l];
    	val+=res[l]+1;
        //cout<<val<<endl;
    	if(AP[u1]){
            //cout<<"hi"<<endl;
    		val--;
    	}
    	if(AP[v1]){
    		val--;
    	}
    	cout<<val<<endl;
    }
    return 0;   
}
