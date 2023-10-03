#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;
typedef long double Double;

#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const Int INF=1010000000000000017LL;
const Int MOD=1000000007LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;

#define REP(i,n) for(Int i = 0; i < n; i++)
#define FOR(i,k,n) for(Int i = k; i < n; i++)

int main(){
    Int n, m, p; cin >> n >> m >> p;
    vector<Int> a(n), b(m);
    REP(i,n) cin >> a[i];
    REP(i,m) cin >> b[i];

    sort(b.begin(), b.end());

    Int asum[m]; asum[0] = b[0];
    FOR(i, 1, m){
        asum[i] = asum[i-1] + b[i];
    }

    Int ans = 0;

    REP(i,n){
        auto it = lower_bound(b.begin(), b.end(), p-a[i]);
        int idx = distance(b.begin(), it);
        if(idx - 1 >= 0){
            ans += a[i] * (idx) + asum[idx-1];
        }
        ans += p * (b.size() - (idx));
    }
    cout << ans << "\n";
    
}
