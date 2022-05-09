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
    Int n;cin>>n;
    Int ans=0;
    if(Int(1e3)<=n)ans+=(min(n,Int(1e6)-1)-Int(1e3)+1);
    if(Int(1e6)<=n)ans+=2*(min(n,Int(1e9)-1)-Int(1e6)+1);
    if(Int(1e9)<=n)ans+=3*(min(n,Int(1e12)-1)-Int(1e9)+1);
    if(Int(1e12)<=n)ans+=4*(min(n,Int(1e15)-1)-Int(1e12)+1);
    if(Int(1e15)==n)ans+=5;
    cout<<ans<<"\n";
}