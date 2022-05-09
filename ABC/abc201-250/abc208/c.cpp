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
    Int N,K;cin>>N>>K;
    vector<pair<pair<Int,Int>,Int>> a(N);
    REP(i,N){cin>>a[i].first.first;a[i].first.second=i;}
    sort(a.begin(),a.end());

    Int k_1=K/N;
    Int dstrbtnable=K-(k_1*N);
    REP(i,N){
        if(i<dstrbtnable)a[i].second=k_1+1;
        else a[i].second=k_1;
    }
    sort(a.begin(),a.end(),[&](auto l,auto r){
        return l.first.second < r.first.second;
    });
    REP(i,N)cout<<a[i].second<<"\n";
}