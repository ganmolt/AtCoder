//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long
#define Double long double
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
#define ll Int
typedef pair<ll,ll> P;
struct Edge{ll from,to,dist;};
ll N,M; ll d[110000],p[110000];
vector<Edge> G[110000];

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
            que.push({dist,e.to});//更新
            p[e.to]=r.second;
        }
    }
}
//-----------------------------------------
int main(void){
    cin>>N>>M;
    REP(i,M){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back({a,b,c});
        G[b].push_back({b,a,c});
    }
    ll d1[N];
    dijkstra(0);
    REP(i,N)d1[i]=d[i];
    ll d2[N];
    dijkstra(N-1);
    REP(i,N)d2[i]=d[i];
    REP(i,N){
        cout<<d1[i]+d2[i]<<"\n";
    }
}
