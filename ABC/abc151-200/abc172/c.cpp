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
    Int n,m,k;cin>>n>>m>>k;
    vector<Int> a(n),b(m);REP(i,n)cin>>a[i];REP(i,m)cin>>b[i];
    vector<Int> sma(n+1),smb(m+1);
    sma[0]=0;smb[0]=0;
    //1ind
    FOR(i,0,n)sma[i+1]=sma[i]+a[i];FOR(i,0,m)smb[i+1]=smb[i]+b[i];
    Int ans=0;
    for(Int i=0;i<=n;i++){
        if(k-sma[i]<0)break;
        auto r=upper_bound(smb.begin(),smb.end(),k-sma[i]);r--;
        Int idx=r-smb.begin();
        chmax(ans,i+idx);
    }
    cout<<ans<<"\n";
}
