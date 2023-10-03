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
    int m; cin >> m;
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    int ans = 1e9;

    REP(i,m){
        REP(j,m){
            REP(k,m){
                if( s1[i] == s2[j] && s2[j] == s3[k] ){
                    int a = 1e9;
                    bool ij = i == j;
                    bool jk = j == k;
                    bool ik = i == k;
                    // printf("(%lld,%lld,%lld, %d,%d,%d)\n", i, j, k, ij, jk, ik);
                    if(!ij && !ik && !jk) a = max({i, j, k});
                    else if(ij && !jk) a = i + m;
                    else if(ik && !jk) a = i + m;
                    else if(!ij && jk) a = j + m;
                    else a = i + m*2;
                    chmin(ans, a);
                    // if(chmin(ans, a)){
                    //     cout << i << "," << j << "," << k << " " << ans <<"\n";
                    // }
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
    
}