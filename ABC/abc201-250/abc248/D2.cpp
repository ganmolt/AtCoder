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
int main(void){
    Int N;cin>>N;
    map<Int,vector<Int>> m;
    REP(i,N){
        Int a;cin>>a;
        m[a].push_back(i);
    }


    Int Q;cin>>Q;
    REP(i,Q){
        Int l,r,x;cin>>l>>r>>x;
        Int L=lower_bound(m[x].begin(),m[x].end(),l-1)-m[x].begin();
        Int R=lower_bound(m[x].begin(),m[x].end(),r)-m[x].begin();
        cout<<R-L<<"\n";
    }
}