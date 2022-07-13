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
Int dp[1<<16][16];
int main(void){
    Int n,m;cin>>n>>m;

    Int d[n][n];
    REP(i,n)REP(j,n)d[i][j]=INF;
    REP(i,m){
        Int s,t,c;cin>>s>>t>>c;
        d[s][t]=c;
    }
    REP(i,(1<<n))REP(j,n)dp[i][j]=INF;
    dp[(1<<n)-1][0]=0;
    for(int s=(1<<n)-2;s>=0;s--){
        for(int v=0;v<n;v++){
            for(int u=0;u<n;u++){
                if(!(s>>u & 1)){
                    dp[s][v]=min(dp[s][v], dp[s|1<<u][u]+d[v][u]);
                }
            }
        }
    }
    cout<<(dp[0][0]==INF?-1:dp[0][0])<<"\n";
}