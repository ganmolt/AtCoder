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
vector<int> cnts(10000001);
//-----------------------------------------

int main(void){
    Int N,K;cin>>N>>K;
    for(int i=2;i<=N;i++){
        if(cnts[i]!=0)continue;
        for(int k=1;i*k<=N;k++){
            cnts[i*k]++;
        }
    }
    Int ans=0;
    for(int i=2;i<=N;i++){
        //cout<<i<<":"<<Fctrs[i].size()<<"\n";
        if(cnts[i]>=K)ans++;
    }
    cout<<ans<<"\n";
}