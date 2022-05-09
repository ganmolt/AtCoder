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
    int A,B,C,D;cin>>A>>B>>C>>D;
    bool isPrime[201];REP(i,201)isPrime[i]=true;
    //isPrime[1]=isPrime[2]=true;
    for(int i=2;i<=200;i++){
        if(isPrime[i]){
            for(int k=2;k*i<=200;k++){
                isPrime[k*i]=false;
            }
        }
    }
    for(int n1=A;n1<=B;n1++){
        bool havePrime=false;
        for(int n2=C;n2<=D;n2++){
            if(isPrime[n1+n2])havePrime=true;
        }
        if(!havePrime){
            cout<<"Takahashi\n";
            exit(0);
        }
    }
    cout<<"Aoki\n";
}