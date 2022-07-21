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
int A,B,C,D,E,F;
bool seen[6600][6600];
double d = -1; int ansa, ansb;
void dfs(int a, int b){
    if(seen[a][b])return;
    seen[a][b]=true;

    if(a*E < b*100)return;
    if(F < a+b)return;

    if(d < 100.0*b/(a+b)){
        d = 100.0*b/(a+b);
        ansa = a;
        ansb = b;
    }

    dfs(a+100*A, b);
    dfs(a+100*B, b);
    dfs(a, b+C);
    dfs(a, b+D);
}
int main(void){
    cin>>A>>B>>C>>D>>E>>F;
    dfs(100*A, 0);
    dfs(100*B, 0);
    cout<<max(ansa+ansb, 100*A)<<" "<<ansb<<"\n";
}