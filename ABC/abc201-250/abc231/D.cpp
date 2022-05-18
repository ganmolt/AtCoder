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
class UnionFind {
public:
    vector <Int> par; // 各元の親を表す配列
    vector <Int> siz; // 素集合のサイズを表す配列(1 で初期化)
    // Constructor
    UnionFind(Int sz_): par(sz_), siz(sz_, 1LL) {
        for (Int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(Int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (Int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    // Member Function
    // Find
    Int root(Int x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }
    // Union(Unite, Merge)
    bool unite(Int x, Int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    bool same(Int x, Int y) { // 連結判定
        return root(x) == root(y);
    }
    Int size(Int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};
//-----------------------------------------
int main(void){
    Int N,M;cin>>N>>M;
    int d[N];REP(i,N)d[i]=0;
    UnionFind uf(N);
    REP(i,M){
        int a,b;cin>>a>>b;
        a--;b--;
        if(uf.same(a,b)){
            cout<<"No\n";
            exit(0);
        }
        uf.unite(a,b);
        d[a]++;
        d[b]++;
    }
    REP(i,N){
        if(d[i]>=3){
            cout<<"No\n";
            exit(0);
        }
    }
    cout<<"Yes\n";
}