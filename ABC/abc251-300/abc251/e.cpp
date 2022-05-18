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
Int dp[330000];
Int dp2[330000];
int main(void){
    int n;cin>>n;
    vector<int> a(n);REP(i,n)cin>>a[i];
    
    REP(i,n+1)dp[i]=dp2[i]=INF;dp[0]=dp[1]=a[0];dp2[0]=a[n-1];
    FOR(i,1,n){
        dp[i+1]=min(dp[i+1],dp[i]+min(a[i],a[i+1]));
        dp[i+2]=min(dp[i+2],dp[i]+a[i+1]);
        //REP(j,n+1)cout<<(dp[j]==INF?-1:dp[j])<<" ";cout<<"\n";
    }
    //cout<<dp[n-1]<<","<<dp[n]<<"\n";
    REP(i,n){
        dp2[i+1]=min(dp2[i+1],dp2[i]+min(a[i],a[i+1]));
        dp2[i+2]=min(dp2[i+2],dp2[i]+a[i+1]);
        //REP(j,n+1)cout<<(dp2[j]==INF?-1:dp2[j])<<" ";cout<<"\n";
    }
    //cout<<dp2[n-2]<<","<<dp2[n-1]<<"\n";
    cout<<min(min(dp[n-1],dp[n]),min(dp2[n-2],dp2[n-1]))<<"\n";
}
    