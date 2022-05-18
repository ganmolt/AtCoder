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
Int dp[220000][10];
int main(void){
    Int N;cin>>N;
    vector<int> a(N);
    REP(i,N)cin>>a[i];
    dp[0][a[0]]=1;
    for(int i=0;i<N-1;i++){
        for(int k=0;k<10;k++){
            dp[i+1][(k+a[i+1])%10]=( dp[i+1][(k+a[i+1])%10] + dp[i][k] )%mod;
            dp[i+1][(k*a[i+1])%10]=( dp[i+1][(k*a[i+1])%10] + dp[i][k] )%mod;
        }
    }
    REP(i,10){
        cout<<dp[N-1][i]<<"\n";
    }
}