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
int main(void){
    int n,q;cin>>n>>q;
    vector<int> x(q);
    REP(i,q)cin>>x[i],x[i]--;
    vector<int> val(n),idx(n);REP(i,n)val[i]=idx[i]=i;
    REP(i,q){
        int p1=idx[x[i]];
        int p2=p1+(1-2*(p1==n-1));
        int v1=val[p1];
        int v2=val[p2];
        swap(val[p1],val[p2]);
        swap(idx[v1],idx[v2]);
    }
    REP(i,n)cout<<val[i]+1<<(i==n-1?"\n":" ");
}