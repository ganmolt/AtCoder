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
int mins[10000][10000];
int main(void){
    int n;cin>>n;
    vector<int> a(n);REP(i,n)cin>>a[i],mins[i][i]=a[i];
    //REP(i,10000)FOR(j,i,10000)mins[i][j]=1e9;
    REP(i,10000)FOR(j,i+1,10000)mins[i][j]=min(mins[i][j-1],a[j]);
    int ans=0;
    REP(i,n)FOR(j,i,n){
        //cout<<i<<","<<j<<":"<<mins[i][j]<<",,"<<(j-i+1)*mins[i][j]<<" ";
        ans=max<int>(ans,(j-i+1)*mins[i][j]);
    }
    cout<<ans<<"\n";
}