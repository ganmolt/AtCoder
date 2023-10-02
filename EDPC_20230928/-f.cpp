#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main(){
    string s, t;
    cin >> s >> t;
    int n1 = s.size();
    int n2 = t.size();
    
    int dp[n1+1][n2+1];
    REP(i,n1+1)REP(j,n2+1)dp[i][j]=0;

    FOR(i,1,n1+1){
        FOR(j,1,n2+1){
            chmax(dp[i][j], dp[i-1][j]);
            chmax(dp[i][j], dp[i][j-1]);
            if(s[i] == t[j]) chmax(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    string ans = "";
    int i = n1;
    int j = n2;
    while(i>=0 && j>=0){
        if(s[i] == t[j]){
            ans += s[i];
            i--;
            j--;
        }
        else if(i>0 && dp[i-1][j] == dp[i][j]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
