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
//-----------------------------------------
Int dp[5500][5500];
int main(void){
    int n,m;cin>>n>>m;
    vector<Int> x(n);REP(i,n)cin>>x[i];
    vector<Int> c(m),y(m);REP(i,m)cin>>c[i]>>y[i];
    Int b[5500];REP(i,5500)b[i]=0;
    REP(i,m){
        b[c[i]]=y[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            chmax(dp[i+1][0],dp[i][j]);
            chmax(dp[i+1][j+1],dp[i][j]+x[i]+b[j+1]);
        }
    }
    Int ans=0;
    REP(i,n+1){
        //cout<<i<<": "<<dp[n][i]<<"\n";
        chmax(ans,dp[n][i]);
    }

    cout<<ans<<"\n";
}