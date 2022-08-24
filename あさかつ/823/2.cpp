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
    int n; cin >> n;
    n++;
    vector<int> t(n), x(n), y(n);
    t[0] = 0, x[0] = 0, y[0] = 0;
    FOR(i,1,n) cin >> t[i] >> x[i] >> y[i];
    
    REP(i,n){
        if(t[i] % 2 != (x[i] + y[i]) % 2) NO;
    }

    FOR(i,1,n){
        if( t[i] - t[i-1] < abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) )NO;
    }
    YES;
}