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
int n,m;
vector<int> G[8];
bool gone[8];int cnt=0;
int ans=0;
void dfs(int i){
    if(cnt==n)ans++;
    for(auto to:G[i]){
        if(gone[to])continue;
        gone[to]=true;cnt++;
        dfs(to);
        gone[to]=false;cnt--;
    }
}
int main(void){
    cin>>n>>m;
    vector<int> a(m),b(m);REP(i,m)cin>>a[i]>>b[i],a[i]--,b[i]--;
    REP(i,m){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    gone[0]=true;cnt++;
    dfs(0);
    cout<<ans<<"\n";
}
