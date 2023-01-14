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
bool isInTri(int px, int py, int ax, int ay, int bx, int by, int cx, int cy){
    double abXap = (bx-ax)*(py-ay) - (by-ay)*(px-ax);
    double bcXbp = (cx-bx)*(py-by) - (cy-by)*(px-bx);
    double caXcp = (ax-cx)*(py-cy) - (ay-cy)*(px-cx);

    bool ba = abXap < 0, bb = bcXbp < 0, bc = caXcp < 0;

    return (ba==bb && bb==bc);
}
int main(void){
    int x[4], y[4];
    REP(i,4) cin >> x[i] >> y[i];

    REP(i,4){
        int j = (i+1) % 4;
        int k = (j+1) % 4;
        int l = (k+1) % 4;

        if(
            isInTri( x[i],y[i], x[j],y[j], x[k],y[k], x[l],y[l] )
        )NO;
    }
    YES;
}

