//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
#define dcml(n) fixed<<setprecision(n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const ll INF=1010000000000000017LL;
const ll MOD=1000000007LL;
const ld EPS=1e-12;
const ld PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define  FORS(i,m,n) for(ll (i)=(m);   (i)<=(n); (i)++)
#define  RFOR(i,m,n) for(ll (i)=(n)-1; (i)>=(m); (i)--)
#define RFORS(i,m,n) for(ll (i)=(n);   (i)>=(m);  (i)--)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
#define WREPS(i,in,j,jn) REPS(i,in)REPS(j,jn)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
struct UnionFind{
    vector<int> par;

    UnionFind(int N): par(N+1){
        for(int i=1;i<=N;i++) par[i]=i;//最初は全てが根
    }

    int root(int x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }

    void unite(int x, int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry)return;
        par[rx]=ry;//xの根rxをyの根ryにつける
    }

    bool same(int x, int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
};
//-----------------------------------------
int main(void){
    ll N,M;
    cin>>N>>M;
    UnionFind uf(N);
    vi v[N+1];
    REPS(i,M){
        ll a,b;cin>>a>>b;
        v[a].push_back(b);
    }

    vi ans(N+1);
    ll cnt=0;
    RFORS(i,1,N){
        //cout<<i<<": ";
        cnt++;
        for(auto r:v[i]){
            if(!uf.same(i,r)){
                uf.unite(i,r);
                cnt--;
                //cout<<i<<"-"<<r<<" ";
            }
        }
        ans[i]=cnt;
    }
    FORS(i,2,N){
        cout<<ans[i]<<"\n";
    }cout<<0<<"\n";
}
