#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)

int main(){
    int n; cin >> n;
    int h[n]; REP(i,n)cin >>h[i];

    int dp[n]; REP(i,n) dp[i] = 1e9;
    dp[0] = 0;
    REP(i,n){
        if(i+1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        if(i+2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }
    cout << dp[n-1] << "\n";
}

