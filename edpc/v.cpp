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
vector<Int> G[110000];
Int n,m;
Int dp1[110000],dp2[110000];
void dfs1(int i, int from=-1){
    Int prod=1;
    for(auto to:G[i]){
        if(to==from)continue;
        dfs1(to,i);
        prod=prod*dp1[to]%m;
    }
    dp1[i]=prod+1;
}

void dfs2(int i, int from=-1){
    if(from==-1)dp2[i]=1;
    vector<Int> lprod=vector<Int>(G[i].size(),1);
    vector<Int> rprod=vector<Int>(G[i].size(),1);  

    REP(j,G[i].size()){     
        int to=G[i][j];
        if(j-1>=0)lprod[j]=lprod[j-1];
        if(to==from)continue;
        lprod[j]=lprod[j]*dp1[to]%m;
    }

    for(Int j=G[i].size()-1;j>=0;j--){     
        int to=G[i][j];
        if(j+1<rprod.size())rprod[j]=rprod[j+1];
        if(to==from)continue;
        rprod[j]=rprod[j]*dp1[to]%m;
    }

    REP(j,G[i].size()){
        int to=G[i][j];
        if(to==from)continue;
        Int rest_prod=1;
        if(j-1>=0)rest_prod=rest_prod*lprod[j-1]%m;
        if(j+1<rprod.size())rest_prod=rest_prod*rprod[j+1]%m;
        dp2[to]=(dp2[i]*rest_prod+1)%m;
        dfs2(to,i);
    }
}
Int ans[110000];
void dfs3(int i, int from=-1){
    ans[i]=dp2[i];
    for(auto to:G[i]){
        if(to==from)continue;
        ans[i]=ans[i]*dp1[to]%m;
        dfs3(to,i);
    }
}   

int main(void){
    cin>>n>>m;
    vector<Int> x(n-1),y(n-1);
    REP(i,n-1)cin>>x[i]>>y[i];

    REP(i,n-1){
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }

    dfs1(1);
    dfs2(1);

    dfs3(1);
    FOR(i,1,n+1){
        cout<<ans[i]<<"\n";
    }
}