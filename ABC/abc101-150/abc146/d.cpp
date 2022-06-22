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
vector<pair<int,int>> G[110000];
vector<int> G2[110000];
vector<int> ans(110000);
void dfs(int pc, int p){
    //cout<<p<<"=>";
    int c=1;
    for(auto to:G[p]){
        //cout<<to<<"(";
        if(c==pc)c++;
        //cout<<c<<"),";
        ans[to.second]=c;
        dfs(c, to.first);
        c++;
        
        
    }
}
//-----------------------------------------
int main(void){
    int n;cin>>n;
    REP(i,n-1){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back({b,i});
        G2[a].push_back(b);
        G2[b].push_back(a);
    }

    int M=0;
    REP(i,n){
        //cout<<G2[i].size()<<"\n";
        chmax<int>(M, G2[i].size());
    }

    dfs(-1, 0);

    cout<<M<<"\n";
    REP(i,n-1)cout<<ans[i]<<"\n";
}