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
typedef pair<ll,long> P;
struct Edge{long to,dist;};
long N; ll d[100000];
vector<Edge> G[100000];

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
vector<long> g[100000];
bool isDenger[100000];
void bfs(ll D,ll ZBs[],ll ZBSZ){//ゾンビの島から ZBs:ゾンビ町の配列,ZBSZ:サイズ
    typedef pair<ll,ll> P;
    queue<P> que;
    REP(i,ZBSZ)que.push(make_pair(ZBs[i],0));//from,距離
    while(!que.empty()){
        P q=que.front();que.pop();
        ll dist=q.second;
        //cout<<q.first+1<<" dist:"<<dist<<":\n";
        if(dist==D)continue;//危険な街の範囲を超えない
        for(auto r:g[q.first]){
            //cout<<r+1<<" ";
            //危険な街認定をすること-------
            isDenger[r]=true;
            que.push(make_pair(r,dist+1));
        }//cout<<"\n";
    }
}

int main(void){
    long M,K,S;cin>>N>>M>>K>>S;// N個の町,M本の道路
    //K個の町はゾンビに支配,S本以下の道路を使っていける町は危険な町
    long P,Q;cin>>P>>Q;//安全な町:P円,危険な町:Q円
    //K行　ゾンビの町
    bool isZB[N];memset(isZB,false,sizeof(isZB));
    ll C[K];
    REP(i,K){
        cin>>C[i];C[i]--;
        isZB[C[i]]=true;
    }
    //M行
    vector<long> A(M),B(M);
    REP(i,M){
        cin>>A[i]>>B[i];A[i]--,B[i]--;
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    //危険な街認定
    bfs(S,C,K);
    //グラフの張り直し
    REP(i,M){
        if(A[i]==N-1){
            G[B[i]].push_back({A[i],0});
        }else if(isZB[A[i]]){
            G[B[i]].push_back({A[i],10000000000000});
        }else if(isDenger[A[i]]){
            G[B[i]].push_back({A[i],Q});
        }else{
            G[B[i]].push_back({A[i],P});
        }
        if(B[i]==N-1){
            G[A[i]].push_back({B[i],0});
        }else if(isZB[B[i]]){
            G[A[i]].push_back({B[i],10000000000000});
        }else if(isDenger[B[i]]){
            G[A[i]].push_back({B[i],Q});
        }else{
            G[A[i]].push_back({B[i],P});
        }
    }
    dijkstra(0);
    //REP(i,N) cout<<i+1<<" "<<isZB[i]<<" "<<isDenger[i]<<" "<<d[i]<<"\n";
    cout<<d[N-1]<<"\n";
}