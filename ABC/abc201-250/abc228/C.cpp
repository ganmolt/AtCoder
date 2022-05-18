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
    int N,K;cin>>N>>K;
    vector<int> sm(N);
    REP(i,N){
        sm[i]=0;int p;
        REP(j,3){
            cin>>p;
            sm[i]+=p;
        }
    }
    vector<int> sm2=sm;
    sort(sm2.begin(),sm2.end());
    REP(i,N){
        auto r=upper_bound(sm2.begin(),sm2.end(),sm[i]+300);
        int lwr=r-sm2.begin()-1;
        int upr=N-lwr;
        if(upr<=K)cout<<"Yes\n";
        else cout<<"No\n";
    }
}