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
vector<Int> dx2={1,0};
vector<Int> dy2={0,1};
vector<Int> dx4={-1,0,1,0};
vector<Int> dy4={0,1,0,-1};
vector<Int> dx5={-1,0,0,1,0};
vector<Int> dy5={0,1,0,0,-1};
vector<Int> dx8={-1,-1,-1,0,0,1,1,1};
vector<Int> dy8={-1,0,1,-1,1,-1,0,1};
vector<Int> dx9={-1,-1,-1,0,0,0,1,1,1};
vector<Int> dy9={-1,0,1,-1,0,1,-1,0,1};
//-----------------------------------------
int H,W;
char C[110][110];
int dp[110][110];
int ans=0;

void solve(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(dp[i][j]==0)continue;
            REP(k,2){
                int nc1=i+dx2[k];
                int nc2=j+dy2[k];
                //cout<<nc1<<","<<nc2<<": ";
                if(0<=nc1 && nc1<H &&
                0<=nc2 && nc2<W &&
                C[nc1][nc2]=='.'){
                    //cout<<nc1<<","<<nc2<<"\n";
                    dp[nc1][nc2]=dp[i][j]+1;
                }//cout<<"\n";

            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans=max(ans,dp[i][j]);
        }
    }

    cout<<ans<<"\n";
}

int main(void){
    cin>>H>>W;
    REP(i,H)REP(j,W)cin>>C[i][j];
    dp[0][0]=1;
    solve();
}
