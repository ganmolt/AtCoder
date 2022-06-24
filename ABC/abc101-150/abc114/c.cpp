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
Int n;Int cnt=0;
void dfs(Int i, bool b3,bool b5,bool b7){
    if(i<=n){
        //cout<<i<<"\n";
        cnt+=(b3&&b5&&b7);
    }
    else return;
    dfs(i*10+3,1,b5,b7);
    dfs(i*10+5,b3,1,b7);
    dfs(i*10+7,b3,b5,1);
}
int main(void){
    cin>>n;
    dfs(7,0,0,1);
    dfs(5,0,1,0);
    dfs(3,1,0,0);
    cout<<cnt<<"\n";
}