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
    Int N;cin>>N;
    vector<Int> A(N);
    REP(i,N){
        Int a;cin>>a;
        A[i]=a;
    }
    for(int i=1;i<N;i++){
        A[i]+=A[i-1];
        A[i]%=360;
    }
    //REP(i,N)cout<<A[i]<<" ";cout<<"\n";
    sort(A.begin(),A.end());
    Int ans=0;
    A.push_back(360);
    for(int i=0;i<N+1;i++){
        if(i==0)ans=max(A[i],ans);
        ans=max(A[i]-A[i-1],ans);
    }
    cout<<ans<<"\n";
}