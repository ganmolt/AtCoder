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
    int n; cin >> n;
    vector<Int> t(n), x(n), a(n);
    REP(i,n) cin >> t[i] >> x[i] >> a[i];

    vector<vector<Int>> snk(5, vector<Int>(200000,0));
    REP(i,n){
        snk[x[i]][t[i]] = a[i];
    }

    vector<vector<Int>> dp(200000, vector<Int>(5, -1));
    dp[0][0] = 0;

    REP(i,110000){
        REP(j,5){
            if(dp[i][j] == -1)continue;
            if(snk[j][i] > 0){
                dp[i][j] += snk[j][i];
            }
        }
        REP(j,5){
            if(j!=0)dp[i+1][j] = max(dp[i+1][j], max(dp[i][j-1], dp[i][j]));
            if(j!=4)dp[i+1][j] = max(dp[i+1][j], max(dp[i][j], dp[i][j+1]));
        }
        
    }
    Int ans = 0;
    REP(i,5){
        chmax(ans, dp[110000][i]);
    }
    cout << ans << "\n";
}