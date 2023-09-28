#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)

int main(){
    int n; cin >> n;
    int a[n][3]; REP(i,n)REP(j,3) cin >> a[i][j];
    int dp[n][3]; REP(i,n)REP(j,3)dp[i][j] = 0;
    REP(j,3) dp[0][j] = a[0][j];

    FOR(i,1,n){
        REP(j,3){
            dp[i][j] = max(
                dp[i][j],
                max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + a[i][j]
            );
        }
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";
}
