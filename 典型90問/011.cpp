//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long
#define Double long double
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
struct Task{
    Int D,C,S;

};
bool operator<(const Task& l, const Task& r){
    return l.D<r.D;
};
//-----------------------------------------
int main(void){
    Int N;cin>>N;
    
    vector<Task> v(N+1);
    for(int i=0;i<N;i++)cin>>v[i].D>>v[i].C>>v[i].S;
    sort(v.begin(),v.end());
    //REP(i,v.size())cout<<v[i].D<<"\n";
    vector<vector<Int>> dp(5500,vector<Int>(5500,0));
    REP(i,N){
        for(int j=0;j<=5000;j++){
            //cout<<i<<","<<j<<":";
            //cout<<j+v[i].C<<","<<v[i].D<<"\n";
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j+v[i+1].C<=v[i+1].D){//仕事が間に合うなら
                dp[i+1][j+v[i+1].C]=max(dp[i+1][j+v[i+1].C],dp[i][j]+v[i+1].S);
            }//cout<<" "<<dp[N][j]<<"\n";
        }
        
    }
    Int ans=0;
    for(int i=0;i<=5000;i++)ans=max(ans,dp[N][i]);
    cout<<ans<<"\n";
}