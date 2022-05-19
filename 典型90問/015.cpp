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
Int fact[110000],invf[110000];
Int mod=1e9+7;
Int nCr(Int n, Int k){
    return fact[n]*invf[n-k]%mod*invf[k]%mod;
}
//-----------------------------------------
int main(void){
    fact[1]=1;
    for(int i=2;i<110000;i++){
        fact[i]=i*fact[i-1]%mod;
    }
    Int n=mod-2;Int res=1;Int a=fact[109999];
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    invf[109999]=res;
    for(Int i=109999;i>0;i--){
        invf[i-1]=invf[i]*i%mod;
    }

    Int N;cin>>N;
    for(Int k=1;k<=N;k++){
        Int ans=0;
        for(Int i=1;N-(k-1)*(i-1)>=i;i++){
            ans=(ans+nCr(N-(k-1)*(i-1),i) )%mod;
        }
        cout<<ans<<"\n";
    }
}