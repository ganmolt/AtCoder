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
typedef pair<ll,ll> P;
struct Edge{ll from,to,dist;};
ll N; ll d[100000];
ll p[100000];
vector<Edge> G[100000];

void dijkstra(ll u){
    REP(i,N)d[i]=p[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,u});
    d[u]=0;
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>d[r.second])continue;//更新不可
        
        for(Edge& e: G[r.second]){
            ll dist=d[r.second]+e.dist;
            if(dist>=d[e.to])continue;//更新不可
            d[e.to]=dist;//更新
            que.push({d[e.to],e.to});//更新
            p[e.to]=r.second;
        }
    }
}
//-----------------------------------------
int main(void){
    ll M;cin>>N>>M;
    REP(i,M){
        ll a,b;cin>>a>>b;a--;b--;
        G[a].push_back({a,b,1});
        G[b].push_back({b,a,1});
    }
    cout<<"Yes\n";
    dijkstra(0);
    REPS(i,N-1)cout<<p[i]+1<<"\n";
}