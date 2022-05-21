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
struct Edge{ll to,yen,snuke;};
ll N; ll dy[101000],ds[101000];
vector<Edge> G[101000];

void dijkstra(ll u,int k=0){
    REP(i,N)d[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,u});
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>=d[r.second])continue;//更新不可
        d[r.second]=r.first;//更新

        for(Edge& e: G[r.second]){
            ll dist;
            if(k==1)dist=d[r.second]+e.snuke;
            else dist=d[r.second]+e.yen;
            if(dist>=d[e.to])continue;//更新不可
            que.push({dist,e.to});//更新
        }
    }
}
//-----------------------------------------
int main(void){
    ll N,M;cin>>N>>M;
    ll s,t;cin>>s>>t;
    REP(i,M){
        ll u,v,a,b;cin>>u>>v>>a>>b;
        u--;v--;
        G[u].push_back({v,a,b});
    }

    dijkstra(s,dy);
    dijkstra(t,ds,1);
    /*  s-> K -> t
        s->Kは円
        K->tはすぬーくを消費
        円+すぬーくが最小なら解
        */
    //i年後を考える　すべて使える---i番目が使えない
    ll ans[N+1];ans[N]=INF;//消費した金額
    //n-i年後はn-1しか使えない
    REP(i,N){
        ans[N-1-i]=min(ans[N-i],dy[N-1-i]+ds[N-1-i]);
    }
    REP(i,N){
        ll a=1000000000000000-ans[i];
        cout<<a<<"\n";
    }
}