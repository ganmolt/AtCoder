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

//-----------------------------------------
Int N;string S;
int main(void){
    cin>>N>>S;
    string atc="atcoder";
    Int cnt[N+1][8];
    REP(i,7)cnt[N][i]=0;
    REP(i,N+1)cnt[i][7]=1;
    for(int i=N-1;i>=0;i--){
        REP(j,7){
            cnt[i][j]=cnt[i+1][j];
            if(S[i]==atc[j])cnt[i][j]=(cnt[i][j]+cnt[i+1][j+1])%MOD;
        }
    }
    cout<<cnt[0][0]%MOD<<"\n";
}