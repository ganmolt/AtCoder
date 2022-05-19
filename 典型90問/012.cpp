//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long
#define Double long double
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
    #define ll Int
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }
    // Union(Unite, Merge)
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    bool same(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }
    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};
//-----------------------------------------
int main(void){
    int H,W;cin>>H>>W;
    int Q;cin>>Q;


    //uid付与
    int uid[H][W];
    REP(i,H){
        REP(j,W){
            uid[i][j]=i*W+j;
        }
    }

    int N=H*W;
    bool isRed[N];REP(i,N)isRed[i]=false;
    UnionFind uf(N);

    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};

    REP(i,Q){
        int q;cin>>q;
        if(q==1){
            int r,c;cin>>r>>c;r--;c--;
            isRed[uid[r][c]]=true;
            for(int di=0;di<4;di++){
                int ny=r+dy[di];
                int nx=c+dx[di];
                if(ny<0||ny>=H || nx<0||nx>=W)continue;
                if(isRed[uid[ny][nx]]){
                    uf.unite(uid[r][c],uid[ny][nx]);
                    //cout<<r<<","<<c<<"-"<<ny<<","<<nx<<"\n";
                }
            }
        }
        else if(q==2){
            int r1,c1,r2,c2;
            cin>>r1>>c1>>r2>>c2;
            r1--;c1--;r2--;c2--;
            if(isRed[uid[r1][c1]]&&isRed[uid[r2][c2]] &&
            uf.same(uid[r1][c1],uid[r2][c2]) ){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }

}