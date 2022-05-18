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
Int N,M,K;
Int mod=998244353;
Int dp[51][2525];
int main(void){
    cin>>N>>M>>K;
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int k=0;k<=K;k++){
            for(int j=1;j<=M;j++){
                if(k+j<=K){
                    dp[i+1][k+j]=(dp[i+1][k+j]+dp[i][k])%mod;
                }
            }
        }
    }
    Int ans=0;
    for(int i=1;i<=K;i++)ans=(ans+dp[N][i])%mod;
    cout<<ans<<"\n";
}