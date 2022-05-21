//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vb vector<bool>
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
#define dcml(n) fixed<<setprecision(n)
//CONST
//------------------------------------------
const ll INF=1010000000000000017LL;
const ll MOD=1000000007LL;
const ld EPS=1e-12;
const ld PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define  FORS(i,m,n) for(ll (i)=(m);   (i)<=(n); (i)++)
#define  RFOR(i,m,n) for(ll (i)=(n)-1; (i)>=(n); (i)--)
#define RFORS(i,m,n) for(ll (i)=(n);   (i)>(n);  (i)--)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
#define WREPS(i,in,j,jn) REPS(i,in)REPS(j,jn)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
const ll D=80*80*2;

ll A[88][88],B[88][88];
bool dp[88][88][2*D];

int main(void){
    ll H,W;cin>>H>>W;
    
    WREP(i,H,j,W)cin>>A[i][j];
    WREP(i,H,j,W)cin>>B[i][j];
    
    WREP(i,H,j,W)A[i][j]-=B[i][j];


    
    
    dp[0][0][D+A[0][0]]=true;
    WREP(i,H,j,W){
        REP(k,D*2){
            if(!dp[i][j][k])continue;//つくれない
            if(i+1<H){
                dp[i+1][j][k+A[i+1][j]]=true;
                dp[i+1][j][k-A[i+1][j]]=true;
            }
            if(j+1<W){
                dp[i][j+1][k+A[i][j+1]]=true;
                dp[i][j+1][k-A[i][j+1]]=true;
            }
        }
    }
    ll ans=INF;
    REP(k,D*2){
        if(dp[H-1][W-1][k]){
            //cout<<k-D<<":"<<abs(k-D)<<" ";
            ans=min(ans,abs(k-D));
        }
    }
    cout<<ans<<"\n";
}