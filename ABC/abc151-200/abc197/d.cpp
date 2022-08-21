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
    Double x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    Double x = (x0 + x1) / 2;
    Double y = (y0 + y1) / 2;

    Double x0_ = x0 - x;
    Double y0_ = y0 - y;

    Double resx = x0_ * cos(2*PI / n) - y0_ * sin(2*PI / n); 
    Double resy = x0_ * sin(2*PI / n) + y0_ * cos(2*PI / n); 

    cout << dcml(10) << x + resx << " " << y + resy << "\n";
}