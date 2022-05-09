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

typedef pair<Int,Int> P;
struct Edge{Int from,to,dist;};
bool operator< (const Edge& l, const Edge& r){
    return l.to<r.to;
}
vector<Edge> G[1100000];
Int n; Int d[1100000],p[1100000];


void dijkstra(Int u){
    REP(i,n)d[i]=p[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,u});
    d[u]=0;
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>d[r.second])continue;//更新不可
        for(Edge& e: G[r.second]){
            Int dist=d[r.second]+e.dist;
            if(dist>=d[e.to])continue;//更新不可
            d[e.to]=dist;//更新
            que.push({dist,e.to});//更新
            p[e.to]=r.second;
        }
    }
}
//-----------------------------------------
vector<Int> dx={1,0};
vector<Int> dy={0,1};
int h,w;
int toIdx(int x,int y){
    return x*w+y;
}
int main(void){
    cin>>h>>w;
    int ch,cw;cin>>ch>>cw;ch--;cw--;
    int dh,dw;cin>>dh>>dw;dh--;dw--;

    char s[h][w];REP(i,h)REP(j,w)cin>>s[i][j];

    UnionFind uf(h*w);
    int wx=-1,wy=-1;
    REP(i,h){
        REP(j,w){
            if(s[i][j]=='#'){
                if(wx==-1){
                    wx=i,wy=j;
                }else{
                    uf.unite(toIdx(i,j),toIdx(wx,wy));
                }
            }
            else{
                for(int k=0;k<2;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<h&&ny<w&&s[nx][ny]=='.'){
                        uf.unite(toIdx(i,j),toIdx(nx,ny));
                    }
                }
            }
        }
    }
    set<int> st;
    REP(i,h)REP(j,w)st.insert(uf.root(toIdx(i,j)));

    map<int,int> cnvrtIdx;
    int ii=0;
    for(auto r:st){
        if(wx>=0&&r==uf.root(toIdx(wx,wy)))cnvrtIdx[r]=-1;
        else cnvrtIdx[r]=ii++;
    }

    vector<vector<int>> IDX(h,vector<int>(w));
    REP(i,h){
        REP(j,w){
            IDX[i][j]=cnvrtIdx[uf.root(toIdx(i,j))];
        }
    }
    n=ii;

    vector<Int> dx24={
                    -2,-2,-2,-2,-2,
                    -1,-1,-1,-1,-1,
                     0, 0,    0, 0,
                     1, 1, 1, 1, 1,
                     2, 2, 2, 2, 2
    };
    vector<Int> dy24={
                    -2,-1, 0, 1, 2,
                    -2,-1, 0, 1, 2,
                    -2,-1,    1, 2,
                    -2,-1, 0, 1, 2,
                    -2,-1, 0, 1, 2,
    };
    set<Edge> GG[n];
    REP(i,h){
        REP(j,w){
            if(IDX[i][j]==-1)continue;
            REP(k,24){
                int nx=i+dx24[k],ny=j+dy24[k];
                if(nx<0||h<=nx||ny<0||w<=ny||IDX[nx][ny]==-1)continue;
                if(IDX[i][j]==IDX[nx][ny])continue;
                GG[IDX[i][j]].insert({IDX[i][j],IDX[nx][ny],1});
                GG[IDX[nx][ny]].insert({IDX[nx][ny],IDX[i][j],1});
            }
        }
    }
    REP(i,n){
        G[i]=vector<Edge>(GG[i].begin(),GG[i].end());
    }

    dijkstra(IDX[ch][cw]);
    cout<<(d[IDX[dh][dw]]==INF?-1:d[IDX[dh][dw]])<<"\n";

}