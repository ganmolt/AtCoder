#include<iostream>
#include<queue>
#define P pair<int,int>
int INF=100000000;

using namespace std;

int N,M;
int sx,sy;
int gx,gy;

char maze[100][100];
int d[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void solve();
int bfs();
int main(){
    cin>>N>>M;
    for(int x=0;x<N;x++)
    for(int y=0;y<M;y++){
        cin>>maze[x][y];
        if(maze[x][y]=='S'){
            sx=x;
            sy=y;
        }
        if(maze[x][y]=='G'){
            gx=x;
            gy=y;
        }
    }
    cout<<gx<<","<<gy<<"\n";
    solve();
}
void solve(){
    int res=bfs();
    cout<<res<<"\n";
}

int bfs(){
    queue<P> que;
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++){
        d[i][j]=INF;
    }
    que.push(P(sx,sy));
    d[sx][sy]=0;

    while(!que.empty()){
        P p=que.front();que.pop();
        if(p.first==gx && p.second==gy)break;
        for(int i=0;i<4;i++){
            int X=p.first+dx[i];
            int Y=p.second+dy[i];
            if(d[X][Y]==INF && maze[X][Y]!='#'){
                d[X][Y]=d[p.first][p.second]+1;
                que.push(P(X,Y));
            }
        }
    }
    return d[gx][gy];
}