//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
//-----------------------------------------
#define dcml(n) fixed<<setprecision(n)
using namespace std;
ll H,W;
char c[500][500];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y){
    if(c[x][y]=='#')return;
    //cout<<x<<","<<y<<"\n";
    if(c[x][y]=='g'){
        cout<<"Yes\n";
        exit(0);
    }
    c[x][y]='#';
    REP(d,4){
        ll X=x+dx[d];ll Y=y+dy[d];
        if(X<0||H<=X||Y<0||W<=Y)continue;
        if(c[X][Y]!='#')dfs(X,Y);
    }
}
int main(void){
    cin>>H>>W;
    WREP(i,H,j,W)cin>>c[i][j];
    WREP(i,H,j,W){
        if(c[i][j]=='s')dfs(i,j);
    }
    cout<<"No\n";
}