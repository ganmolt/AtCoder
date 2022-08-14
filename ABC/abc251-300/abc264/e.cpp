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
bool isEvnt[550000];
bool isElec[550000];

int main(void){
    Int n, m, e; cin >> n >> m >> e;
    vector<pair<int,int>> vp;
    REP(i,e){
        int u, v; cin >> u >> v; u--, v--;
        vp.push_back({u,v});
    }


    Int q; cin >> q;
    vector<Int> x(q);
    REP(i,q){
        cin >> x[i]; x[i]--;
        isEvnt[x[i]] = true;
    }

    Int cnt = 0;
    UnionFind uf(n+m);
    REP(i,e){
        if(isEvnt[i] == true) continue;
        int u = vp[i].first;
        int v = vp[i].second;

        if( u >= n && v >= n )continue;
        if( u < n && v < n){
            if(isElec[uf.root(u)] && !isElec[uf.root(v)]){
                isElec[uf.root(v)] = true;
                cnt += uf.size(v);
            }
            if(!isElec[uf.root(u)] && isElec[uf.root(v)]){
                isElec[uf.root(u)] = true;
                cnt += uf.size(u);
            }

            uf.unite(u, v);
            continue;
        }
        if( u >= n && v < n ){
            if(isElec[uf.root(v)]) continue;
            isElec[uf.root(v)] = true;
            cnt += uf.size(v);
            continue;
        } else if ( u < n && v >= n ){
            if(isElec[uf.root(u)]) continue;
            isElec[uf.root(u)] = true;
            cnt += uf.size(u);
            continue;
        }
    }

    vector<Int> ans;
    for(int i = q-1; i >= 0; i--){
        ans.push_back(cnt);
        int u = vp[x[i]].first;
        int v = vp[x[i]].second;

        if( u >= n && v >= n )continue;
        if( u < n && v < n){
            if(isElec[uf.root(u)] && !isElec[uf.root(v)]){
                isElec[uf.root(v)] = true;
                cnt += uf.size(v);
            }
            if(!isElec[uf.root(u)] && isElec[uf.root(v)]){
                isElec[uf.root(u)] = true;
                cnt += uf.size(u);
            }

            uf.unite(u, v);
            continue;
        }
        if( u >= n && v < n ){
            if(isElec[uf.root(v)]) continue;
            isElec[uf.root(v)] = true;
            cnt += uf.size(v);
            continue;
        } else if ( u < n && v >= n ){
            if(isElec[uf.root(u)]) continue;
            isElec[uf.root(u)] = true;
            cnt += uf.size(u);
            continue;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto r:ans){
        cout << r << "\n";
    }

}
