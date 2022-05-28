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
Int dp[330][330][330];
int main(void){
    int n;cin>>n;
    Int x,y;cin>>x>>y;
    vector<int> a(n),b(n);REP(i,n)cin>>a[i]>>b[i];
    REP(i,n+1)REP(p,x+1)REP(q,y+1)dp[i][p][q]=1e9;
    REP(i,n+1)dp[i][0][0]=0;

    for(int i=0;i<n;i++){
        REP(p,x+1)REP(q,y+1){
            chmin(dp[i+1][min(x,p+a[i])][min(y,q+b[i])],dp[i][p][q]+1);
            chmin(dp[i+1][p][q],dp[i][p][q]);
        }
    }
    cout<<(dp[n][x][y]==1e9?-1:dp[n][x][y])<<"\n";
}