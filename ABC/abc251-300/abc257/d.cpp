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
int main(void){
    Int n;cin>>n;
    vector<Int> x(n),y(n),p(n);REP(i,n)cin>>x[i]>>y[i]>>p[i];

    //vector<pair<int,int>> G[220];
    Int d[220][220];
    REP(i,n){
        REP(j,n){
            if(i==j)continue;
            Int dist=abs(x[i]-x[j])+abs(y[i]-y[j]);
            d[i][j]=(dist+p[i]-1)/p[i];
            d[j][i]=(dist+p[j]-1)/p[j];
            //G[i].push_back({j,d});
            //G[j].push_back({i,d});
        }
    }
    //REP(i,n)REP(j,n)d[i][j]=INF;
    REP(i,n)d[i][i]=0;
    for (int k = 0; k < n; k++){       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], max(d[i][k],d[k][j]));
            }
        }
    }
    Int ans=INF;
    REP(i,n){
        Int tmp=0;
        REP(j,n){
            //cout<<d[i][j]<<" ";
            chmax(tmp,d[i][j]);
        }//cout<<"\n";
        chmin(ans,tmp);
    }
    cout<<ans<<"\n";
}