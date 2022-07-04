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
    Int n,x;cin>>n>>x;
    vector<Int> a(n),b(n);REP(i,n)cin>>a[i]>>b[i];

    vector<Int> A(n);A[0]=0;
    FOR(i,1,n){
        A[i]=A[i-1]+a[i-1]+b[i-1];
    }
    Int ans=INF*8;
    REP(i,n){
        Int tmp=A[i]+a[i];
        if(x-i<0)continue;
        tmp+=b[i]*(x-i);
        //cout<<tmp<<"\n";
        chmin<Int>(ans,tmp);
    }
    cout<<ans<<"\n";
}
