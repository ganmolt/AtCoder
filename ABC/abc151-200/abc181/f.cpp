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
struct Edge{Int a, b; Double c;};
int main(void){
    Int n;cin>>n;
    vector<Int> x(n),y(n);
    REP(i,n)cin>>x[i]>>y[i];

    priority_queue<
        Edge,
        vector<Edge>,
        function<bool(Edge,Edge)>
    > que([](Edge l, Edge r){
        return l.c > r.c;
    });

    auto dist = [&](int i,int j) -> Double {
        return sqrt( (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]) );
    };
    REP(i,n){
        FOR(j,i+1,n){
            que.push({i,j,dist(i,j)});
        }
    }
    Int s=n,t=n+1;
    REP(i,n){
        que.push({i,s,y[i]+100.0});
        que.push({i,t,100.0-y[i]});
    }
    /*
    Double ymin=1e9,ymax=-1e9;
    Int ansm=-1,ansM=-1;
    REP(i,n){
        if(chmin<Double>(ymin,y[i]))ansm=i;
        if(chmax<Double>(ymax,y[i]))ansM=i;
    }
    
    que.push({s,ansm,abs(ymin-(-100))});
    que.push({ansM,t,abs(100-ymax)});
    cout<<s<<","<<t<<"\n";
    cout<<ymin<<","<<ymax<<"\n";
*/
    UnionFind uf(n+2);

    while(!que.empty()){
        auto r=que.top();que.pop();
        if(!uf.same(r.a,r.b)){
            uf.unite(r.a,r.b);
        }else{

        }
        if(uf.same(s,t)){
            cout<<dcml(10)<<r.c/2<<"\n";
            exit(0);
        }
    }
    
}