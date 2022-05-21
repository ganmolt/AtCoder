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
Int dp[3300][3300];
Int mod=998244353;
int main(void){
    int n;cin>>n;
    vector<Int> a(n),b(n);REP(i,n)cin>>a[i];REP(i,n)cin>>b[i];
    Int M=0;REP(i,n)chmax(M,b[i]);
    for(int k=a[n-1];k<=b[n-1];k++){
        dp[n-1][k]=1;
    }
    for(int i=n-1;i>0;i--){
        for(int j=b[i]-1;j>=0;j--){
            dp[i][j]+=dp[i][j+1];
            dp[i][j]%=mod;
        }
        for(int k=a[i-1];k<=b[i-1];k++){
            dp[i-1][k]+=dp[i][k];
            dp[i-1][k]%=mod;
        }
    }
    for(int j=b[0]-1;j>=0;j--){
        dp[0][j]+=dp[0][j+1];
        dp[0][j]%=mod;
    }

    cout<<dp[0][a[0]]<<"\n";
}