//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    Int T;cin>>T;
    Int L,X,Y;cin>>L>>X>>Y;

    Int Q; cin>>Q;
    Double x=0,y,z;
    Double r=L/2.0;
    REP(i,Q){
        Int q;cin>>q;
        Double t=-PI/2+2*PI*q/T;
        y=0-r*cos(t);
        z=r+r*sin(t);
        Double dx=X-x,dy=Y-y;
        Double d=sqrt(dx*dx+dy*dy);
        cout<<dcml(12)<<abs(atan(z/d)/PI*180)<<"\n";
    }
}
