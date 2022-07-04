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
    int a,b;cin>>a>>b;

    int an=(a+50-1)/50;
    int bn=(b+50-1)/50;
    //o
    cout<<3*(an+bn)<<" "<<100<<"\n";
    while(a>0){
        REP(i,100)cout<<"#";cout<<"\n";
        REP(i,50){
            if(a-->1)cout<<"#.";
            else cout<<"##";
        }cout<<"\n";
        REP(i,100)cout<<"#";cout<<"\n";
    }
    //x
    while(b>0){
        REP(i,100)cout<<".";cout<<"\n";
        REP(i,50){
            if(b-->1)cout<<"#.";
            else cout<<"..";
        }cout<<"\n";
        REP(i,100)cout<<".";cout<<"\n";
    }
}