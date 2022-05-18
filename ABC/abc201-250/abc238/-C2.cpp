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
Int mod=998244353;

Int getDigit(Int x){
    Int ret=1;
    while(x>=10){
        x/=10;
        ret++;
    }
    return ret;
}
Int powm(Int x,Int n,Int mod=INF){
    Int ans=1;
    for(Int i=1;i<n;i++){
        ans*=x;
    }
    return ans;
}
Int solve(Int x){
    Int ans=0;
    
    while(x>=10){
        //cout<<"x: "<<x<<", ";
        Int cnt=x-powm(10,getDigit(x))+1;
        //cout<<"cnt: "<<cnt<<", ";
        ans=ans+(cnt*(cnt+1)*499122177)%mod;
        if(ans<0)ans+=mod;
        ans%=mod;
        x-=cnt;
        //cout<<"toX: "<<x<<"\n";
    }
    ans=ans+(x*(x+1)/2)%mod;
    return ans%mod;

}
int main(void){
    Int N;cin>>N;
    cout<<solve(N)<<"\n";
}
