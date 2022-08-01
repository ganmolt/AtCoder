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
class UnionFind{
    vector<Int> par,sz;

public:
    UnionFind(Int n) :par(n), sz(n,1){ for(int i=0;i<n;i++)par[i]=i; }

    Int root(Int x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }

    bool unite(Int x, Int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
        return true;
    }

    bool same(Int x, Int y){ return root(x)==root(y); }

    Int size(Int x){
        return sz[root(x)];
    }
};
//-----------------------------------------
int main(void){
    int n,m;cin>>n>>m;
    vector<int> u(m),v(m);REP(i,m)cin>>u[i]>>v[i],u[i]--,v[i]--;

    bool b[n][n];REP(i,n)REP(j,n)b[i][j]=false;
    REP(i,m){
        b[u[i]][v[i]]=true;
        b[v[i]][u[i]]=true;
    }

    int cnt=0;
    REP(i,n){
        FOR(j,i+1,n){
            if(!b[i][j])continue;
            FOR(k,j+1,n){
                if(!b[i][k])continue;
                if(!b[j][k])continue;

                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}