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

//-----------------------------------------
Int N,X;
Int ans=0;
vector<Int> Balls[20];
void dfs(Int i,Int x){//i-1までの積
    if(i==N){
        if(x==X)ans++;
        return;
    }
    for(auto r:Balls[i]){
        if(x*r>X)continue;
        dfs(i+1,x*r);
    }
}

void solve(){
    dfs(0,1);
    cout<<ans<<"\n";
}
int main(void){
    //総積がXとなるような取り出し方は何通りか
    cin>>N>>X;
    REP(i,N){
        Int L;cin>>L;
        REP(j,L){
            Int a;cin>>a;
            Balls[i].push_back(a);
        }
    }
    solve();
}