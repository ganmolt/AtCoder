#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main(){
    int n, W; cin >> n >> W;
    int w[n], v[n]; REP(i,n) cin >> w[i] >> v[i];

    Int dp[n+1][W+1]; REP(i,n+1) REP(j,W+1) dp[i][j] = 0;
    REP(i,n) dp[i][0] = 0;
    REP(j,W+1) dp[n][j] = 0;

    REP(i,n){
        REP(j,W){
            if(dp[i][j] < 0) continue;
            chmax(dp[i+1][j], dp[i][j]);
            if(i+1<=n && j+w[i] <= W)
                chmax(dp[i+1][j+w[i]], dp[i][j] + v[i]);
        }  
    }

    Int ans = 0;
    REP(j,W+1) chmax(ans, dp[n][j]);
    cout << ans << "\n";
}
