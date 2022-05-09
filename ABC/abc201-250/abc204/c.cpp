//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
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
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//-----------------------------------
bool ok[2200][2200];
vector<Int> G[2200];
void dfs(int i, int s){
    if(s==-1)s=i;
    if(ok[s][i])return;
    ok[s][i]=true;
    for(auto to:G[i]){
        dfs(to,s);
    }
}
int main(void){
    Int n,m;cin>>n>>m;
    REP(i,m){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
    }
    REP(i,n)REP(j,n)ok[i][j]=false;
    Int ans=0;
    for(int i=0;i<n;i++){
        dfs(i,-1);
        REP(j,n)ans+=ok[i][j];
    }
    cout<<ans<<"\n";
}