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
int dp[3300][3300];
int main(void){
    string s,t;cin>>s>>t;
    int n=s.size(),m=t.size();
    REP(i,3300)dp[i][0]=dp[0][i]=0;

    string ans;
    REP(i,n){
        REP(j,m){
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            if(s[i]==t[j]){
                chmax(dp[i+1][j+1], dp[i][j]+1);
            }
        }
    }

    string rewsna = "";
    while(n > 0 && m > 0 ){
        if(dp[n][m] == dp[n-1][m])n--;
        else if(dp[n][m] == dp[n][m-1])m--;
        else{
            n--;
            m--;
            rewsna += s[n];
        }
    }
    reverse(rewsna.begin(),rewsna.end());
    cout<<rewsna<<"\n";
}