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
string s;
Int mod=1e9+7;
Int dp[110000][9];
int main(void){
    cin>>s;
    string chkd="chokudai";
    //cout<<chkd.size()<<"n\n";
    REP(i,110000)REP(j,9)dp[i][j]=-1;
    REP(i,s.size()+1)dp[i][chkd.size()]=1;

    for(int i=s.size()-1;i>=0;i--){
        for(int k=chkd.size()-1;k>=0;k--){
            dp[i][k]=max(dp[i][k],dp[i+1][k]);
            if(dp[i+1][k+1]>=0 && s[i]==chkd[k]){
                dp[i][k]=(max(0ll,dp[i][k])+dp[i+1][k+1])%mod;
            }
        }
    }
    /*
    cout<<dp[4][2]<<"\n";
    REP(i,s.size()){
        cout<<s[i]<<": ";
        REP(j,chkd.size()){
            cout<<(dp[i][j]==-1?"_":to_string(dp[i][j]))<<" ";
        }cout<<"\n";
    }
    cout<<"   ";
    REP(i,chkd.size())cout<<chkd[i]<<" ";cout<<"\n";
    /*
    REP(i,chkd.size()+1){
        cout<<"dp["<<s.size()<<"]["<<i<<"]:";
        cout<<dp[s.size()][i]<<"\n";
    }cout<<"\n";*/
    Int ans=max(dp[0][0],0ll);
    cout<<ans<<"\n";
}