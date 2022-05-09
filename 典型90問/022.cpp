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
Int GCD(Int a,Int b) { return b ? GCD(b,a%b) : a; }
Int LCM(Int a,Int b) { return a/GCD(a,b)*b; }
Int Factorial(Int n){ Int m=1;while(n>=1)m*=n--;return m; }
Int pow(Int a, Int b, Int mod=INF){
    Int res=1;
    while(b>0){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
Int getDigit(Int num){
    Int digit=0; 
    while(num!=0){num/=10;digit++;}
    return digit;
}
//-----------------------------------------
int main(void){
    Int x,y,z;cin>>x>>y>>z;
    Int r=GCD(x,GCD(y,z));
    cout<<(x/r-1)+(y/r-1)+(z/r-1)<<"\n";

}