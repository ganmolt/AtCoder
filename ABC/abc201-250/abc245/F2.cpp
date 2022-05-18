//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const Int INF=1010000000000000017LL;
const Int MOD=1000000007LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
Int N,M;
vector<int> G[220000];
bool gone[220000];
int res[220000];
bool dfs(int x){
    if(res[x]>=0)return res[x];
    if(gone[x])return res[x]=1;


    gone[x]=1;
    bool ret=0;
    for(auto to:G[x]){
        if(dfs(to))ret=1;
        gone[to]=0;
    }
    return res[x]=ret;
}

void solve(){
    Int ans=0;
    REP(i,N){
        ans+=dfs(i);
        gone[i]=false;
    }
    cout<<ans<<"\n";
}
int main(void){
    cin>>N>>M;
    REP(i,M){
        int u,v;cin>>u>>v;u--;v--;
        G[u].push_back(v);
    }
    REP(i,N)gone[i]=false;
    REP(i,N)res[i]=-1;
    solve();
}