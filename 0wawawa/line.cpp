#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Board{
  struct P{int x,y;};
  int N;
  vector<vector<char>> c;
  int ans=100;//INF 7*7だから十分
  vector<vector<P>> anss;
  //4方向への移動用
  int dy[4]={-1,0,1,0};
  int dx[4]={0,1,0,-1};
public:
  Board(int n):N(n){
      c.resize(N);
      for(int i=0;i<N;i++)c[i].resize(N);
      input();
      init();
  };
  void input(){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        cin>>c[i][j];
      }
    }
  }
  void init(){
      /*四隅からbfs*/
      queue<P> que;
      if(c[0][0]=='x'){c[0][0]='X';que.push({0,0});}
      if(c[0][N-1]=='x'){c[0][N-1]='X';que.push({0,N-1});}
      if(c[N-1][0]=='x'){c[N-1][0]='X';que.push({N-1,0});}
      if(c[N-1][N-1]=='x'){c[N-1][N-1]='X';que.push({N-1,N-1});}
      while(!que.empty()){
        P r=que.front();que.pop();
        for(int k=0;k<4;k++){
            int X=r.x+dx[k],Y=r.y+dy[k];//各方向に進んだ位置
            if(!(0<=X&&X<N and 0<=Y&&Y<N))continue;//範囲外ならcontinue
            if(c[Y][X]=='x'){
                /*
                これだと
                xx.
                .xx
                ..x
                には対応できるが
                xx.
                .x.
                .xx
                の場合でも中央が固定されてしまう問題がある
                */
                c[Y][X]='X';//反転不可能な壁に変える
                que.push({Y,X});
            }
        }
      }
  }
  void solve(){
    queue<P> que;
    for(int y=0;y<N;y++){
      for(int x=0;x<N;x++){
        if(c[y][x]!='.')continue;//〇が置けないならcontinue
        //4方向の1か所でもXがあれば実行
        bool putable=false;//置けるかどうか
        for(int k=0;k<4;k++){
          int X=x+dx[k],Y=y+dy[k];//各方向に進んだ位置
          if(!(0<=X&&X<N and 0<=Y&&Y<N))continue;//範囲外ならcontinue
          if(c[Y][X]=='x'){putable=true;break;}
        }
        if(putable){
            que.push({y,x});
        }
      }
    }
    cout<<que.size()<<"\n";
    while(!que.empty()){
      P r=que.front();que.pop();
      cout<<r.x<<" "<<r.y<<"\n";
      //ans=max(ans,dfs(P));　最小値を求めるdfs
    }
  }
  int dfs(P){

  }
};
int main(int argc, char *argv[]) {
  int N;cin>>N;
  Board board(N);
  board.solve();
  
  return 0;
}
