//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
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

//-----------------------------------------
int main(void){
    Int N,X;cin>>N>>X;
    vector<Int> a(N),b(N);
    REP(i,N){
        cin>>a[i]>>b[i];
    }
    bool dp[11000][110];REP(i,11000)REP(j,110)dp[i][j]=false;
    dp[0][0]=true;
    for(int x=0;x<=X;x++){
        for(int k=0;k<N;k++){
            //dp[X][k+1]=a[k],b[k]後に位置Xにいるか
            if(dp[x][k]){
                dp[x+a[k]][k+1]=true;
                dp[x+b[k]][k+1]=true;
            }
        }
    }
    if(dp[X][N]){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}