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
    Int n;cin>>n;
    vector<Int> a(n),b(n),c(n);
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    REP(i,n){cin>>c[i];c[i]--;}

    vector<Int> d(n);
    REP(i,n)d[i]=b[c[i]];

    map<Int,Int> m1,m2;
    REP(i,n)m1[a[i]]++;
    REP(i,n)m2[d[i]]++;
    Int ans=0;
    REP(i,n+1){
        ans+=m1[i]*m2[i];
    }
    cout<<ans<<"\n";
}