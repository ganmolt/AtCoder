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

typedef pair<ll,ll> P;
struct Edge{ll to,dist;};
ll N; ll d[50];
vector<Edge> G[50];

struct Exchange{
    ll n,t;
};
vector<Exchange> E[50];


void dijkstra(ll u){
    REP(i,N)d[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    priority_queue<pair<ll,P>,vector<pair<ll,P>>,less<pair<ll,P>>> qc;
    que.push({0,u});
    while(!que.empty()){
        auto r=que.top();que.pop();
        qc.push(E[r.second].n,E[r.second].t);
        if(r.first>=d[r.second])continue;//更新不可
        d[r.second]=r.first;//更新

        for(Edge& e: G[r.second]){
            ll dist=d[r.second]+e.dist;
            if(dist>=d[e.to])continue;//更新不可
            que.push({dist,e.to});//更新
        }
    }
}

struct EdgeC{ll to,cost;};
ll c[50];
vector<EdgeC> H[50];
ll S;

void dijkstraC(ll u){
    REP(i,N)c[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    
    ll silver=S;
    que.push({0,u});//cost,from
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>=c[r.second])continue;//更新不可
        c[r.second]=r.first;//更新

        for(EdgeC& e: H[r.second]){
            ll cost=c[r.second]+e.cost;
            if(cost>=c[e.to])continue;//更新不可
            que.push({cost,e.to});//更新
        }
    }
}
int main(void){
    cin>>N;ll M;cin>>M>>S;

    REP(i,M){
        ll u,v,a,b;cin>>u>>v>>a>>b;
        u--;v--;
        G[u].push_back({v,b});
        G[v].push_back({u,b});
        H[u].push_back({v,a});
        H[v].push_back({u,a});
    }
    //最短距離
    dijkstra(0);
    //最安運賃
    dijkstraC(0);

    REP(i,N){
        ll c,d;cin>>c>>d;
    }

    

    FOR(i,1,N){
        cout<<d[i]<<" "<<c[i]<<"\n";
    }
}