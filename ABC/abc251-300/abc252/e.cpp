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
//-----------------------------------------
int n,m;
struct Edge{int to,cost,idx;};
vector<Edge> G[220000];
Int d[220000];
int p[220000];

void dijkstra(int s){
    REP(i,n)d[i]=1e18;
    REP(i,n)p[i]=-1;
    priority_queue<pair<Int,int>, vector<pair<Int,int>>, greater<pair<Int,int>> >que;
    d[s]=0;
    que.push({0,s});
    
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(d[r.second]<r.first)continue;
        for(auto nxt:G[r.second]){
            if(d[nxt.to]>d[r.second]+nxt.cost){
                d[nxt.to]=d[r.second]+nxt.cost;
                que.push({d[nxt.to],nxt.to});
                p[nxt.to]=nxt.idx;//r.second; //経路復元の代わりにidx
            }
        }
    }
}


int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        G[a].push_back({b,c,i});
        G[b].push_back({a,c,i});
    }
    dijkstra(0);
    /*
    REP(i,n){
        cout<<i<<": "<<d[i]<<"\n";
    }
    for(int i=0;i<n;i++){
        auto r=i;
        cout<<r;r=p[r];
        while(r!=-1){
            cout<<"->";
            cout<<r;
            r=p[r];
        }cout<<"\n";
    }*/
    for(int i=1;i<n;i++)cout<<p[i]+1<<(i==n-1?"\n":" ");
}