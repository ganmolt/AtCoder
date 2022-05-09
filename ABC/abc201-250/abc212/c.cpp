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
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    REP(i,n)cin>>a[i];
    REP(i,m)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i1=0,i2=0;
    Int ans=INF;
    while(i1<n&&i2<m){
        if(a[i1]<b[i2])chmin<Int>(ans,abs(b[i2]-a[i1++]));
        if(a[i1]>=b[i2])chmin<Int>(ans,abs(b[i2++]-a[i1]));
    }
    cout<<ans<<"\n";
}