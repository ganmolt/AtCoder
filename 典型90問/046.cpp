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
    vector<Int> a(n),b(n),c(n);REP(i,n)cin>>a[i];REP(i,n)cin>>b[i];REP(i,n)cin>>c[i];
    map<int,Int> m1,m2,m3;
    REP(i,n) m1[a[i]%46]++;
    REP(i,n) m2[b[i]%46]++;
    REP(i,n) m3[c[i]%46]++;

    Int ans=0;
    for(auto [k1,v1]:m1){
        for(auto [k2,v2]:m2){
            for(auto [k3,v3]:m3){
                if((k1+k2+k3)%46==0){
                    ans+=v1*v2*v3;
                }
            }
        }
    }
    cout<<ans<<"\n";
}