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
    Int n;cin>>n;
    vector<Int> a(n);REP(i,n)cin>>a[i];
    UnionFind uf(220000);

    REP(i,n/2){
        Int l=a[i],r=a[n-1-i];
        if(l==r)continue;
        uf.unite(l,r);
    }
    bool gone[220000];REP(i,220000)gone[i]=false;
    Int ans=0;
    REP(i,220000){
        if(gone[uf.root(i)])continue;
        gone[uf.root(i)]=true;
        ans+=uf.size(uf.root(i))-1;
    }
    cout<<ans<<"\n";
}