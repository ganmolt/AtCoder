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
Int mod=998244353;
Int dp[1100][5500];
int main(void){
    Int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++)dp[0][i]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]+=dp[i][j-1];
        }
        for(int j=0;j<=m;j++){
            if(j-k>=0)dp[i+1][j]+=dp[i][j-k];
            if(j+k-1<=m)dp[i+1][j]+=(dp[i][m]-dp[i][j+k-1]);
            dp[i+1][j]%=mod;
        }
    }
    cout<<dp[n][m]<<"\n";
}