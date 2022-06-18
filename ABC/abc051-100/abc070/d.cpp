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
struct Edge{int to; Int c;};
vector<Edge> G[110000];
Int d[110000];

void dfs(int i, Int c, int from=-1){
    for(auto r:G[i]){
        if(r.to==from)continue;
        if(d[r.to]>=c+r.c){
            d[r.to]=c+r.c;
            dfs(r.to, d[r.to], i);
        }
    }
}

int main(void){
    int n;cin>>n;
    REP(i,n-1){
        int a,b,c;cin>>a>>b>>c,a--,b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    int q,k;cin>>q>>k;k--;
    vector<int> x(q),y(q);
    REP(i,q)cin>>x[i]>>y[i],x[i]--,y[i]--;
    REP(i,n)d[i]=INF;

    d[k]=0;
    dfs(k,0);
    REP(i,q){
        cout<<d[x[i]]+d[y[i]]<<"\n";
    }
}