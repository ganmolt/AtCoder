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

Double DD(Int x1, Int y1, Int x2, Int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
//-----------------------------------------
int main(void){
    int n;cin>>n;
    Double sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    vector<Int> x(n),y(n),r(n);REP(i,n)cin>>x[i]>>y[i]>>r[i];
    Int e1,e2;
    REP(i,n){
        Int dsx=x[i]-sx,dsy=y[i]-sy;
        if(dsx*dsx+dsy*dsy==r[i]*r[i])e1=i;

        Int dtx=x[i]-tx,dty=y[i]-ty;
        if(dtx*dtx+dty*dty==r[i]*r[i])e2=i;

    }

    UnionFind uf(n);
    REP(i,n){
        FOR(j,i+1,n){
            Double dd=DD(x[i],y[i],x[j],y[j]);
            if(dd<=(r[i]+r[j])*(r[i]+r[j])){
                Int Mr=max(r[i],r[j]),mr=min(r[i],r[j]);
                if(dd>=(Mr-mr)*(Mr-mr))uf.unite(i,j);
            }
        }
    }

    if(uf.same(e1,e2))YES;
    NO;
}