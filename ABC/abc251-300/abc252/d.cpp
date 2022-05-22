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
uintmax_t com(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  uintmax_t dividend = 1;
  uintmax_t divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}
Int fact(Int k){
    Int sum = 1;
    for (Int i=1;i<=k;i++) sum *= i;
    return sum;
}
//-----------------------------------------
int main(void){
    int n;cin>>n;
    vector<int> a(n);REP(i,n)cin>>a[i];
    map<Int,Int> m;
    REP(i,n)m[a[i]]++;
    Int sm=0;for(auto r:m)sm+=r.second;
    Int ans=0;
    /*
    for(auto r:m){
        for(auto q:m){
            if(r.first==q.first)continue;
            ans+=r.second*q.second*(n-r.second-q.second);
        }
    }*/
    Int s=0;
    for(auto r:m)s+=r.second;
    Int ans0=0;
    for(auto r:m){
        ans0+=r.second*(s-r.second);
    }ans0/=2;ans0*=s;
    Int ans1=0;
    for(auto r:m){
        ans1+=r.second*r.second*(s-r.second);
    }ans/=2;

    ans=ans0-ans1;

    cout<<ans/3<<"\n";
}