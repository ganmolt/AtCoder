#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

vector<int> G[110000];
int dp[110000];
bool gone[110000];
int f(int i){
    if(gone[i]) return dp[i];
    gone[i] = true;

    int ans = 0;
    for(auto to:G[i]){
        chmax(ans, f(to) + 1);
    }
    return dp[i] = ans;
}
int main(){
    int n, m; cin >> n >> m;

    REP(i,m){
        int x, y; cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
    }

    int ans = 0;
    REP(i,n) chmax(ans, f(i));
    cout << ans << "\n";
}


