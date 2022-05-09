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
struct Edge{ll to,dist;};
ll N; ll d[100];
vector<Edge> G[100];

void dijkstra(ll u){
    REP(i,N)d[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,u});
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>=d[r.second])continue;//更新不可
        d[r.second]=r.first;//更新

        for(Edge& e: G[r.second]){
            ll dist=d[r.second]+e.dist;
            if(dist>=d[e.to])continue;//更新不可
            que.push({dist,e.to});//更新
        }
    }
}
//-----------------------------------------
int main(void){
    ll Q;cin>>N>>Q;
    REP(i,Q){
        ll q;cin>>q;
        if(q==0){//客の注文票
            ll a,b;cin>>a>>b;a--;b--;
            //旅行可能なら最短経路、でないなら-1
            dijkstra(a);
            cout<<(d[b]==INF?-1:d[b])<<"\n";
        }
        else{//船舶の運行情報
            ll c,d,e;cin>>c>>d>>e;c--;d--;
            G[c].push_back({d,e});
            G[d].push_back({c,e});
        }
    }
}