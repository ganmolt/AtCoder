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
Int dp[55][55][2525];
int main(void){
    int n,a;cin>>n>>a;
    vector<int> x(n);REP(i,n)cin>>x[i];
    dp[0][0][0]=1;
    REP(i,n){
        REP(j,n){
            REP(k,2500){
                dp[i+1][j][k]+=dp[i][j][k];
                dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
            }
        }
    }
    Int ans=0;
    FOR(i,1,n+1)ans+=dp[n][i][i*a];
    cout<<ans<<"\n";
}
