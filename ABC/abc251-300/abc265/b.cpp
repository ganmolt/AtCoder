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
    Int n, m, T; cin >> n >> m >> T;
    vector<Int> a(n);
    REP(i,n-1) cin >> a[i];

    vector<Int> x(m), y(m);
    REP(i,m){
        //cout << i << ": ";
        cin >> x[i] >> y[i];
        x[i]--;
        //cout  << x[i] << y[i] << "\n";
    }

    vector<Int> bns(n, 0);

    REP(i,m) {
        bns[x[i]] = y[i];
    }

    Int t = T;
    REP(i,n-1) {
        t += bns[i];
        t -= a[i];
        if( t <= 0 ){
            NO;
        }
    }
    YES;
}