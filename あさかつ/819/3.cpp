//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const Int INF=1010000000000000017LL;
const Int MOD=1000000007LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//-----------------------------------------
int main(void){
    string s; cin >> s;
    int n = s.size();
    
    vector<Int> l(n+1,0), r(n+1,0);

    for(int i = 0; i < n; i++){
        if(s[i] == '<'){
            if(i == 0) l[i+1] = 1;
            else l[i+1] = l[i]+1;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '>'){
            if(i == n-1) r[i] = 1;
            else r[i] = r[i+1]+1;
        }
    }
    Int ans = 0;
    REP(i,n+1) ans += max(l[i], r[i]);
    cout << ans << "\n";

    //REP(i,n+1) cout << l[i] << " "; cout << "\n";
    //REP(i,n+1) cout << r[i] << " "; cout << "\n";
}