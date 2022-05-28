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

Int gcd(Int a, Int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
Int lcm(Int a, Int b){
  return a*b / gcd(a, b);
}
//-----------------------------------------
int main(void){
    Int n,a,b;cin>>n>>a>>b;Int ab=lcm(a,b);
    Int sm=n*(n+1)/2;
    Int smA=0,smB=0,smAB=0;
    Int cA=0,cB=0,cAB=0;
    
    cA=(n/a);
    smA=cA*(cA+1)/2*a;
    //cout<<cA<<","<<smA<<"\n";

    cB=(n/b);
    smB=cB*(cB+1)/2*b;
    //cout<<cB<<","<<smB<<"\n";

    cAB=(n/ab);
    smAB=cAB*(cAB+1)/2*ab;
    //cout<<ab<<","<<cAB<<","<<smAB<<"\n";

    cout<<sm-smA-smB+smAB<<"\n";
    //cout<<Int(1e9)*Int(1e9+1)<<"\n";
}