#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main(){
    Int n,W; cin >> n >> W;
    Int w[n], v[n];
    REP(i,n) cin >> w[i] >> v[i];

    vector<vector<Int>> dp(n+1, vector<Int>(100001, 9e18));

    dp[0][0] = 0;

    REP(i,n){
        REP(j,100001){
            chmin(dp[i+1][j], dp[i][j]);
            if(j+v[i] <= 100000) chmin(dp[i+1][j+v[i]], dp[i][j]+w[i]);
        }
    }

    Int ans = 0;
    REP(j,100001){
        if(dp[n][j] <= W){
            chmax(ans, j);
        } 
    }

    cout << ans << "\n";
}
