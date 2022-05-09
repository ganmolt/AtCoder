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
vi dx8={-1,-1,-1,0,0,1,1,1};
vi dy8={-1,0,1,-1,1,-1,0,1};
//-----------------------------------------
ll w,h;
int c[50][50];
bool is;
void dfs(int x,int y){
    if(c[x][y]==0)return;
    c[x][y]=0;
    //cout<<x<<y<<"->";
    is=true;
    REP(i,8){
        int X=x+dx8[i],Y=y+dy8[i];
        if(0<=X&&X<h and 0<=Y&&Y<w){
            if(c[X][Y]==0)continue;
            dfs(X,Y);
        }
    }
}
int main(void){
    while(cin>>w>>h and !(w==0&&h==0) ){
        //cout<<"w:"<<w<<"h:"<<h<<"\n";
        int cnt=0;
        REP(i,h)REP(j,w)cin>>c[i][j];
        REP(i,h)REP(j,w){
            is=false;
            dfs(i,j);//cout<<"\n";
            if(is)cnt++;
        }
        cout<<cnt<<"\n";
    }
}