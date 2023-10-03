#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)
#define REPS(i,n) for(Int i = 1; i <= n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

bool checker(int);

int main(){
    int n; cin >> n;

    cout << (checker(n) ? "Yes" : "No") << "\n";
    
}

bool checker(int x){
    bool is321 = true;

    string s = to_string(x);
    FOR(i, 1, s.size()){
        if(s[i] >= s[i-1]){
            is321 = false;
            break;
        }
    }
    return is321;
}