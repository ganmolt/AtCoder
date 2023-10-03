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
    int k; cin >> k;k--;
    vector<Int> n123;

    for(int i = 2; i < (1<<10); i++){
        Int x = 0;
        for(int j = 9; j >= 0; j--){
            if(i & (1<<j)){
                x *= 10;
                x += j;
            }
        }
        n123.push_back(x);
    }

    sort(n123.begin(), n123.end());

    cout << n123[k] << "\n";
    
}
