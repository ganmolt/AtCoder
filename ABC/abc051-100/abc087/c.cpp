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
    int n;cin>>n;
    vector<int> a(n),b(n);REP(i,n)cin>>a[i];REP(i,n)cin>>b[i];
    vector<int> A(n),B(n);
    REP(i,n){
        if(i==0)A[i]=a[i];
        else A[i]=A[i-1]+a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1)B[i]=b[i];
        else B[i]=B[i+1]+b[i];
    }
    Int ans=0;
    REP(i,n){
        chmax<Int>(ans,A[i]+B[i]);
    }
    cout<<ans<<"\n";
}
