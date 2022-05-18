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
    Int L,Q;cin>>L>>Q;
    vector<Int> c(Q),x(Q);
    REP(i,Q){
        cin>>c[i]>>x[i];
    }
    set<Int> s;s.insert(0);s.insert(L);
    
    REP(i,Q){
        if(c[i]==1){
            s.insert(x[i]);
        }
        if(c[i]==2){
            auto r=s.upper_bound(x[i]);
            auto r2=s.upper_bound(x[i]);r2--;
            cout<<*r-*r2<<"\n";
        }
    }
    
}