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
    int x,y;cin>>x>>y;
    int a[7]={1,3,5,7,8,10,12};
    int b[4]={4,6,9,11};
    int c[1]={2};
    int fa=-1,fb=-1;
    for(int i=0;i<7;i++){
        if(a[i]==x)fa=0;
        if(a[i]==y)fb=0;
    }
    for(int i=0;i<4;i++){
        if(b[i]==x)fa=1;
        if(b[i]==y)fb=1;
    }
    for(int i=0;i<1;i++){
        if(c[i]==x)fa=2;
        if(c[i]==y)fb=2;
    }
    if(fa==fb)YES;
    NO;
}