//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long
#define Double long double
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
    Int H,W;cin>>H>>W;
    vector<vector<Int>> A(H,vector<Int>(W));
    vector<Int> sH(W),sW(H);
    REP(i,H)REP(j,W){
        int a;cin>>a;
        A[i][j]=a;
        sH[j]+=a;
        sW[i]+=a;
    }
    REP(i,H){
        REP(j,W){
            cout<<sH[j]+sW[i]-A[i][j]<<" ";
        }cout<<"\n";
    }
}