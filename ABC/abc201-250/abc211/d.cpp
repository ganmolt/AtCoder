//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
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
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
typedef pair<Int,Int> P;
struct Edge{Int from,to,dist;};
Int N,M; Int d[220000],p[220000],cnt[220000];
vector<Edge> G[220000];
Int mod=1e9+7;

void dijkstra(Int u){
    REP(i,N)d[i]=p[i]=INF;
    cnt[u]=1;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,u});
    d[u]=0;
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>d[r.second])continue;//更新不可

        for(Edge& e: G[r.second]){
            Int dist=d[r.second]+e.dist;
            if(dist>d[e.to])continue;//更新不可
            if(dist==d[e.to]){
                cnt[e.to]=(cnt[e.to]+cnt[r.second])%mod;
                continue;
            }
            cnt[e.to]=cnt[r.second];
            d[e.to]=dist;//更新
            que.push({dist,e.to});//更新
            p[e.to]=r.second;
        }
    }
}
void solve(){
    dijkstra(0);
    if(d[N-1]!=INF)cout<<cnt[N-1]<<"\n";
    else cout<<0<<"\n";
}
int main(void){
    cin>>N>>M;
    REP(i,M){
        Int a,b;cin>>a>>b;a--;b--;
        G[a].push_back({a,b,1});
        G[b].push_back({b,a,1});
    }

    solve();
}