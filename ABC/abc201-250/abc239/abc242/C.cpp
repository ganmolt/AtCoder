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
Int mod=998244353;
Int N;
Int dp[2200000][10];

int main(void){
    cin>>N;
    for(int i=1;i<=9;i++)dp[1][i]=1;
    for(int i=1;i<=N;i++){
        for(int k=1;k<=9;k++){
            if(k>=2){
                dp[i][k]+=dp[i-1][k-1]%=mod;
            }
            dp[i][k]+=dp[i-1][k]%=mod;
            if(k<=8){
                dp[i][k]+=dp[i-1][k+1]%=mod;
            }
        }
    }
    Int ans=0;
    for(int i=1;i<=9;i++){
        ans=(ans+dp[N][i])%mod;
    }
    cout<<ans%mod<<"\n";
}