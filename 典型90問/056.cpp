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
vector<bool> dp[110][110000];
int main(void){
    int n,s;cin>>n>>s;
    vector<int> a(n),b(n);REP(i,n)cin>>a[i]>>b[i];

    dp[1][a[0]]={0};
    dp[1][b[0]]={1};
    FOR(i,1,n){
        REP(j,s){
            if(!dp[i][j].empty()){
                if(j+a[i]<=s)dp[i+1][j+a[i]]=dp[i][j],dp[i+1][j+a[i]].push_back(0);
                if(j+b[i]<=s)dp[i+1][j+b[i]]=dp[i][j],dp[i+1][j+b[i]].push_back(1);
            }
        }
    }
    if(dp[n][s].empty()){
        cout<<"Impossible\n";
    }else{
        for(auto r:dp[n][s]){
            cout<<char(r+'A');
        }
        cout<<"\n";
    }
}