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
const int inf=1e9;
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
int dp[1100][1100][4];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main(void){
    int h,w;cin>>h>>w;
    int sx,sy,gx,gy;cin>>sx>>sy>>gx>>gy;sx--,sy--,gx--,gy--;
    char c[h][w];REP(i,h)REP(j,w)cin>>c[i][j];
    REP(i,h)REP(j,w)REP(k,4)dp[i][j][k]=inf;
    REP(k,4)dp[sx][sy][k]=0;

    deque< pair<int,pair<int,int>> > que;
    que.push_front({0,{sx,sy}});
    while(!que.empty()){
        auto [d,xy]=que.front();que.pop_front();
        auto [x,y]=xy;
        REP(k,4){
            REP(k2,4){
                int nx=x+dx[k2],ny=y+dy[k2];
                if(c[nx][ny]=='#')continue;
                if(nx<0||nx>=h||ny<0||ny>=w)continue;
                if(k==k2){
                    if(chmin(dp[nx][ny][k2],dp[x][y][k]))que.push_front({d,{nx,ny}});
                }
                else{
                    if(chmin(dp[nx][ny][k2],dp[x][y][k]+1))que.push_back({d+1,{nx,ny}});
                }
            }
        }

    }
    int ans=inf;
    REP(k,4)chmin(ans,dp[gx][gy][k]);
    cout<<ans<<"\n";
}