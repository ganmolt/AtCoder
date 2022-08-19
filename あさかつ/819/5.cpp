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
Int pow(Int x, Int n, Int mod=MOD){
    Int ret=1;
    while(n>0){
        if(n&1)ret=ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}
//-----------------------------------------
int main(void){
    int h, w; cin >> h >> w;
    char c[h][w]; REP(i,h)REP(j,w) cin >> c[i][j];

    
    Int okc = 0; REP(i,h)REP(j,w) if(c[i][j] == '.')okc++;

    int noCnt[h][w][2]; REP(i,h)REP(j,w)REP(k,2) noCnt[i][j][k] = 0;

    REP(i,h){
        int cnt = 0;
        for(int j = 0; j < w; j++){
            if(c[i][j] == '.') cnt++;
            else cnt = 0;
            noCnt[i][j][0] = cnt;
        }
        for(int j = w-2; j >= 0; j--){
            if(noCnt[i][j][0] != 0) chmax(noCnt[i][j][0], noCnt[i][j+1][0]);
        }
    }

    REP(j,w){
        int cnt = 0;
        for(int i = 0; i < h; i++){
            if(c[i][j] == '.') cnt++;
            else cnt = 0;
            noCnt[i][j][1] = cnt;
        }
        for(int i = h-2; i >= 0; i--){
            if(noCnt[i][j][1] != 0) chmax(noCnt[i][j][1], noCnt[i+1][j][1]);
        }
    }

    Int ans = okc * pow(2, okc, MOD);
    //cout << okc << "," << pow(2, okc, MOD) << "\n";
    //cout << ans << "\n";
    REP(i,h){
        REP(j,w){
            if(c[i][j] == '#')continue;
            Int noc = noCnt[i][j][0] + noCnt[i][j][1] - 1;
            ans = (ans - pow(2, okc - noc, MOD) + MOD);
            ans = ans % MOD;
            //cout << ans << "\n";
        }
    }
    cout << ans << "\n";

}