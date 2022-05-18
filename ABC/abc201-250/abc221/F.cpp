//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
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
vector<Int> G[400009];
Int dist[400009];
Int parent[400009];
Int N;
void getDist(Int from){
    REP(i,N*2-1)dist[i]=INF;
    queue<pair<Int,Int>> que;
    que.push({from,0});dist[from]=0;
    while(!que.empty()){
        auto r=que.front();que.pop();
        //cout<<"now:"<<r.first<<":\n";
        //cout<<"to: ";
        for(auto to: G[r.first]){
            if(dist[to]==INF){
                //cout<<to<<" ";
                dist[to]=r.second+1;
                parent[to]=r.first;
                que.push({to,dist[to]});
            }
        }//cout<<"\n";
    }
}
Int D;
Int dp[400009];
void dfs(Int x,Int last=INF){
    if(last==INF)dist[x]=0;
    else parent[x]=last;

    if(dist[x]==D/2)dp[x]=1;
    for(auto to:G[x]){
        if(to==last)continue;
        dist[to]=dist[x]+1;
        dfs(to,x);
        dp[x]+=dp[to];
    }
}

//-----------------------------------------
int main(void){
    cin>>N;
    REP(i,N-1){
        Int u,v;cin>>u>>v;u--;v--;
        G[u].push_back({N+i});
        G[N+i].push_back({v});
        G[v].push_back({N+i});
        G[N+i].push_back({u});
    }
    getDist(0);
    Int M=-1,Mpos=-1;
    REP(i,2*N-1){
        if(M<dist[i]){
            M=dist[i];
            Mpos=i;
        }
    }
    getDist(Mpos);
    Int M2=-1,M2pos=-1;
    REP(i,2*N-1){
        if(M2<dist[i]){
            M2=dist[i];
            M2pos=i;
        }
    }
    //nowは木の中心
    D=M2;Int now=M2pos;
    for(int i=0;i<D/2;i++){
        //cout<<now<<"->";
        now=parent[now];
    }
    //中心から直径の半分の位置なら1、から木dp
    //----------------------------
    REP(i,N*2-1)dp[i]=0;
    
    dfs(now);
    Int mod=998244353;
    Int ans=1;
    for(auto r:G[now]){
        ans=ans*(dp[r]+1)%mod;
    }
    ans=(ans+mod-1-dp[now])%mod;
    cout<<ans<<"\n";
}