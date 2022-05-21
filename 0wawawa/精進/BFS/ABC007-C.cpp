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
vi dx4={-1,0,1,0};
vi dy4={0,1,0,-1};
vi dx5={-1,0,0,1,-1};
vi dy5={0,1,0,0,-1};
vi dx8={-1,-1,-1,0,0,1,1,1};
vi dy8={-1,0,1,-1,1,-1,0,1};
vi dx9={-1,-1,-1,0,0,0,1,1,1};
vi dy9={-1,0,1,-1,0,1,-1,0,1};
//-----------------------------------------
typedef pair<ll,ll> P;
ll R,C;
ll d[55][55];
char c[50][50];
void bfs(P s){
    queue<P> que;
    d[s.first][s.second]=0;
    que.push(s);
    while(!que.empty()){
        P q=que.front();que.pop();
        ll x=q.first,y=q.second;
        REP(i,4){
            ll X=x+dx4[i];ll Y=y+dy4[i];
            if(!(0<=X&&X<R and 0<=Y&&Y<C))continue;
            if(!(c[X][Y]=='.'))continue;
            if(d[X][Y]==INF){
                d[X][Y]=d[x][y]+1;
                que.push(make_pair(X,Y));
            }
        }
    }
}
int main(void){
    cin>>R>>C;
    REP(i,R)REP(j,C)d[i][j]=INF;
    P S,G;cin>>S.first>>S.second>>G.first>>G.second;
    S.first--,S.second--,G.first--,G.second--;
    REP(i,R){
        REP(j,C){
            cin>>c[i][j];
        }
    }
    bfs(S);
    cout<<d[G.first][G.second]<<"\n";
}