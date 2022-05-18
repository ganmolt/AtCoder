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
char c[1500][1500];
int main(void){
    int n;cin>>n;
    int sx,sy,gx,gy;cin>>sx>>sy>>gx>>gy;
    sx--;sy--;gx--;gy--;
    REP(i,n)REP(j,n){
        cin>>c[i][j];
    }
    vector<int> G[n*n];

    vector<vector<vector<int>>> d(n,vector<vector<int>>(n,vector<int>(4,1e9)));
    deque<tuple<int,int,int>> que;

    for(int dir=0;dir<4;dir++){
        d[sx][sy][dir]=1;
        que.push_back({sx,sy,dir});
    }

    int dx[4]={1,1,-1,-1};
    int dy[4]={1,-1,-1,1};

    //0-1bfs
    while(!que.empty()){
        auto [x,y,dir]=que.front();que.pop_front();

        for(int ndir=0;ndir<4;ndir++){
            int nx=x+dx[ndir],ny=y+dy[ndir];
            if(false
            ||nx<0||n<=nx
            ||ny<0||n<=ny
            )continue;
            if(c[nx][ny]=='#')continue;

            int cost=(ndir!=dir);
            if(chmin(d[nx][ny][ndir],d[x][y][dir]+cost)){
                if(!cost)que.push_front({nx,ny,ndir});
                else que.push_back({nx,ny,ndir});
            }
        }
    }
    int res=1e9;
    for(int dir=0;dir<4;dir++)chmin(res,d[gx][gy][dir]);
    cout<<(res==1e9?-1:res)<<"\n";
}
