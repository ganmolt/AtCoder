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
    int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
    if(r1==r2&&c1==c2){
        cout<<0<<"\n";
        exit(0);
    }
    //1
    if(r1+c1==r2+c2){
        cout<<1<<"\n";
        exit(0);
    }
    if(r1-c1==r2-c2){
        cout<<1<<"\n";
        exit(0);
    }
    if(abs(r1-r2)+abs(c1-c2)<=3){
        cout<<1<<"\n";
        exit(0);
    }
    //2
    if((r1+c1)%2==(r2+c2)%2){
        cout<<2<<"\n";
        exit(0);
    }
    if(abs((r1+c1)-(r2+c2))<=3){
        cout<<2<<"\n";
        exit(0);
    }
    if(abs((r1-c1)-(r2-c2))<=3){
        cout<<2<<"\n";
        exit(0);
    }
    if(abs(r1-r2)+abs(c1-c2)<=6){
        cout<<2<<"\n";
        exit(0);
    }
    //3
    cout<<3<<"\n";
}
