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
    Int n,k;cin>>n>>k;
    //vector<int> w(n),p(n);REP(i,n)cin>>w[i]>>p[i];
    vector<pair<Int,Int>> wp(n);REP(i,n)cin>>wp[i].second>>wp[i].first;
    sort(wp.begin(),wp.end(),greater<pair<Int,Int>>());
    REP(i,n)cout<<wp[i].second<<","<<wp[i].first<<"\n";
    Double ww=0,c=0;
    REP(i,k){
       ww+=wp[i].second;
       c+=wp[i].second*1.0*wp[i].first/100;
    }
    cout<<dcml(10)<<c/ww<<"\n";
}
