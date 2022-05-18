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
int main(void){
    int mod=MOD;
    int n,m;cin>>n>>m;
    vector<int> a(m);
    REP(i,m)cin>>a[i];
    bool ok[110000];REP(i,110000)ok[i]=true;
    REP(i,m)ok[a[i]]=false;

    Int dp[110000];dp[0]=1;
    for(int i=0;i<n;i++){
        if(ok[i+1])dp[i+1]=(dp[i+1]+dp[i])%mod;
        if(ok[i+2])dp[i+2]=(dp[i+2]+dp[i])%mod;
    }
    cout<<dp[n]<<"\n";
}
