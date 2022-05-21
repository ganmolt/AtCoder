#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0; i<(int)n; i++)
#define INF 1e9

const int MAXN=16;
int n;
int d[MAXN][MAXN];
int dp[1<<MAXN][MAXN];

int rec(int S, int v) {
    if(dp[S][v] >= 0) return dp[S][v];
    if(S==(1<<n)-1 && v==0) return dp[S][v]=0;
    int tmp=INF;
    REP(u,n) if(!(S>>u & 1)) tmp=min(tmp, rec(S|1<<u,u)+d[v][u]);
    return dp[S][v]=tmp;
}

int main() {
    int m;
    cin>>n>>m;
    REP(i,n) REP(j,n) d[i][j]=d[j][i]=INF;
    REP(i,m) {int a,b,c; cin>>a>>b>>c; d[a][b]=c;}
    fill((int *)dp, (int *)(dp+(1<<MAXN)), -1);
    cout << rec(0,0) << endl;
    return 0;
}