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
bool dp[110][110000];
int main(void){
    int n;cin>>n;
    vector<int> t(n);
    REP(i,n)cin>>t[i];
    Int sm=0;
    REP(i,n)sm+=t[i];
    Int h=(sm+1)/2;
    REP(i,n)dp[i][0]=true;

    for(int j=0;j<=100000;j++){
        for(int i=0;i<n;i++){
            if(dp[i][j])dp[i+1][j+t[i]]=true;
            if(dp[i][j])dp[i+1][j]=true;
        }
    }
    for(int i=h;i<=sm;i++){
        if(dp[n][i]){
            cout<<i<<"\n";
            exit(0);
        }
    }
}
