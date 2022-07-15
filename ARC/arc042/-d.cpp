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
Int pow(Int x, Int n, Int mod=1e9+7){
    Int ret=1;
    while(n>0){
        if(n&1)ret=ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}
//-----------------------------------------
int main(void){
    Int x,p,a,b;cin>>x>>p>>a>>b;
    Int m=sqrt(p);
    //vector<Int> baby(m+1);
    map<Int,Int> m;
    //baby[0]=1;
    Int z=1;
    for(int i=0;i<=m;i++){
        //baby[i]=baby[i-1]*x%p;
        z = z * x % p;
        m[z] = i;
    }
/*
x^k=i(a<=i<=b)となるkを求めたい
k=cm+d;
x^(cm+d) (mod p) = i
<=> x^d = i*(x^(-m))^c (mod p)
*/
    Int r = powmod(z, p-2, p);// r = x^(-m)
    Int rn = r;
    for(int i=1;i<=m;i++){
        rn*=r;
    }