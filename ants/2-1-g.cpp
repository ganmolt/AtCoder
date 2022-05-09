#include<iostream>

using namespace std;

int N,M;
char A[100][100];
int solve();
void dfs(int ,int );
int main(){
    cin>>N>>M;
    for(int x=0;x<N;x++)
    for(int y=0;y<M;y++)
    cin>>A[x][y];

    cout<<solve()<<"\n";
}
int solve(){
    int cnt=0;
    for(int x=0;x<N;x++)
    for(int y=0;y<M;y++){
        if(A[x][y]=='W'){
            dfs(x,y);
            cnt++;
        }
    }
    return cnt;
}
void dfs(int x, int y){
    A[x][y]='.';
    for(int dx=-1;dx<=1;dx++)
    for(int dy=-1;dy<=1;dy++){
        if(A[x+dx][y+dy]=='W'&&
        0<=x+dx&&x+dx<N&&
        0<=y+dy&&y+dy<M
        )dfs(x+dx,y+dy);
    }

}