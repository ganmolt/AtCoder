#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)


int main(){
    int n; cin >> n;
    int k; cin >> k;

    int h[n]; REP(i,n) cin>>h[i];
    // コストの総和の最小
    int dp[n]; REP(i,n) dp[i] = 1e9;
    dp[0] = 0;
    
    REP(i,n){
        REPS(j,k){
            if(i+j >= n) break;
            dp[i+j] = min(dp[i+j], dp[i] + abs(h[i]-h[i+j]));
        }
    }
    cout << dp[n-1] << "\n";
}
