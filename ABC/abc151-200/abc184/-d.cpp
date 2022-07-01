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
pair<double, int> dp[110][110][110];
pair<double, int> dfs(int i, int j, int k, int n){
    if(dp[i][j][k]!={-1,-1})return dp[i][j][k];
    return dp[i][j][k]=dfs(i-1, j, k)+dfs(i, j-1, k)+dfs(i, j, k-1);
}
int main(void){
    int a,b,c;cin>>a>>b>>c;
    
    REP(i,a)REP(j,b)REP(k,c)dp[i][j][k]={-1,-1};
    dp[a][b][c]={0,0};
    for(int j=1;j<=99;i++){
        for(int k=1;k<=99;i++){
            pair<double, int> p=dp[100][j][k];
            cout<<i<<": "<<p.first<<", "<<p.second<<"\n";
        }
    }
}