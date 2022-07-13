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
Int a[20][20];
Int cost[1<<16];
Int dp[1<<16];
int main(void){
    int n;cin>>n;
    REP(i,n)REP(j,n)cin>>a[i][j];

    for(int s=0;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( ( s&(1<<i) ) && ( s&(1<<j) ) )cost[s]+=a[i][j];
            }
        }
    }

    dp[0]=0;
    for(int s=0;s<(1<<n);s++){
        for(int t=s;t>0;t=(t-1)&s){
            //if(t==s)continue;
            dp[s]=max(dp[s],dp[s-t]+cost[t]);
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
}