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
ll N,M;
char c[100][100];
int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x,int y){
    if(c[x][y]=='W'){
        c[x][y]='.';
        REP(d,8){
            int X=x+dx[d];int Y=y+dy[d];
            if(X<0||N<=X||Y<0||M<=Y)continue;
            if(c[X][Y]=='W'){
                dfs(X,Y);
            }
        }
    }
}
int main(void){
    cin>>N>>M;
    REP(i,N)REP(j,M){
        cin>>c[i][j];
    }
    ll cnt=0;
    REP(i,N)REP(j,M){
        if(c[i][j]=='W'){
            cnt++;
            dfs(i,j);
        }
    }
    cout<<cnt<<"\n";
}