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
vector<Int> G[220000];
Int N,M;
bool gone[220000];

void dfs(Int i,Int from=-1){
    for(auto to:G[i]){
        if(to==from)continue;
        if(gone[to]){
            cout<<"No\n";
            exit(0);
        }
        gone[to]=true;
        dfs(to,i);
        gone[to]=false;
    }
}
void solve(){
    REP(i,N){
        set<Int> s(G[i].begin(),G[i].end());
        vector<Int> v(s.begin(),s.end());
        G[i]=v;
    }
    REP(i,N){
        if(G[i].size()>=3){
            cout<<"No\n";
            exit(0);
        }
    }

    gone[0]=true;
    dfs(0);
    gone[0]=false;
    cout<<"Yes\n";
}
//-----------------------------------------
int main(void){
    cin>>N>>M;
    REP(i,M){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve();
}