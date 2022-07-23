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
vector<Int> x(220000);
Int top20[220000][20];
vector<Int> G[220000];


void dfs(int i, int from=-1){
    //cout<<i<<"=>";
    vector<Int> tmp;
    tmp.push_back(x[i]);
    for(auto to:G[i]){
        if(to==from)continue;
        dfs(to,i);
        REP(j,20)tmp.push_back(top20[to][j]);
    }
    //cout<<i<<": ";for(auto r:tmp)cout<<r<<" ";cout<<"\n";
    sort(tmp.begin(),tmp.end(),greater<Int>());
    
    REP(j,min<Int>(tmp.size(),20))top20[i][j]=tmp[j];
}
int main(void){
    Int n,q;cin>>n>>q;
    vector<Int> a(n-1),b(n-1),v(q),k(q);
    REP(i,n)cin>>x[i];
    REP(i,n-1)cin>>a[i]>>b[i],a[i]--,b[i]--;
    REP(i,q)cin>>v[i]>>k[i],v[i]--,k[i]--;

    REP(i,n-1){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    dfs(0);


    REP(i,q){
        cout<<top20[v[i]][k[i]]<<"\n";
    }


}

