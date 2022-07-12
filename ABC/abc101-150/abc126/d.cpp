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
int d[110000];
vector<pair<int,int>> G[110000];
void dfs(int i, int dist, int from=-1){
    for(auto to:G[i]){
        if(to.first==from)continue;
        d[to.first]=(dist+to.second)%2;
        dfs(to.first,d[to.first],i);
    }
}
int main(void){
    int n;cin>>n;
    vector<int> u(n-1),v(n-1),w(n-1);
    REP(i,n-1)cin>>u[i]>>v[i]>>w[i],u[i]--,v[i]--;
    REP(i,n-1){
        G[u[i]].push_back({v[i],w[i]});
        G[v[i]].push_back({u[i],w[i]});
    }

    REP(i,110000)d[i]=-1;
    d[0]=0;
    dfs(0,0);

    REP(i,n){
        cout<<d[i]<<"\n";
    }


}
