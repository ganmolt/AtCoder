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
    Int N,K;cin>>N>>K;
    vector<int> a(N);
    REP(i,N)cin>>a[i];

    vector<Int> A(N+1);
    for(int i=1;i<=N;i++){
        A[i]=A[i-1]+a[i-1];
    }
    map<Int,Int> m;

    Int ans=0;
    for(int r=0;r<=N;r++){
        Int Sl=A[r]-K;
        //cout<<Sl<<":"<<m[Sl]<<" ";
        //cout<<"今は"<<A[r-1]<<"を記録";
        //m[A[r-1]]++;
        ans+=m[Sl];
        m[A[r]]++;
        //cout<<"\n";
    }//cout<<"\n";
    cout<<ans<<"\n";
}