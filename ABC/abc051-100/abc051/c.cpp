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
    int sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
    int dx=tx-sx;
    int dy=ty-sy;

    if(!dx&&!dy){
        cout<<"\n";
        return 0;
    }

    char fX='R',bX='L';
    char fY='U',bY='D';

    if(dx<0)fX^=bX^=fX^=bX;
    if(dy<0)fY^=bY^=fY^=bY;

    if(dx==0){
        REP(i,dy)cout<<fY;
        cout<<bX;
        REP(i,dy)cout<<bY;
        cout<<fX;

        cout<<fX;
        REP(i,dy)cout<<fY;
        cout<<bX;

        cout<<fY;
        cout<<bX<<bX;
        REP(i,dy+2)cout<<bY;
        cout<<fX<<fX;
        cout<<fY;

        cout<<"\n";
        return 0;
    }
    if(dy==0){
        REP(i,dx)cout<<fX;
        cout<<bY;
        REP(i,dx)cout<<bX;
        cout<<fY;

        cout<<fY;
        REP(i,dx)cout<<fX;
        cout<<bY;

        cout<<fX;
        cout<<bY<<bY;
        REP(i,dx+2)cout<<bX;
        cout<<fY<<fY;
        cout<<fX;

        cout<<"\n";
        return 0;
    }

    if(dx<0)fX^=bX^=fX^=bX;
    if(dy<0)fY^=bY^=fY^=bY;

    REP(i,dx)cout<<fX;
    REP(i,dy)cout<<fY;

    REP(i,dx)cout<<bX;
    REP(i,dy)cout<<bY;

    cout<<bY;
    REP(i,dx+1)cout<<fX;
    REP(i,dy+1)cout<<fY;
    cout<<bX;
    cout<<fY;
    REP(i,dx+1)cout<<bX;
    REP(i,dy+1)cout<<bY;
    cout<<fX;

    cout<<"\n";
    return 0;

}

    
