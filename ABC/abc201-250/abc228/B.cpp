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
Int n,x;
int a[220000];
bool gone[220000];
int ans=0;
//-----------------------------------------
void dfs(int x, int v){
    if(gone[a[x]]){
        ans=v+1;
        return;
    }
    gone[a[x]]=true;
    dfs(a[x], v+1);
}

void solve(){
    gone[x]=true;
    dfs(x,0);
    cout<<ans<<"\n";
}

int main(void){
    cin>>n>>x;x--;
    REP(i,n){
        int aa;cin>>aa;aa--;
        a[i]=aa;
    }

    solve();
}