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
    Int H,W;cin>>H>>W;
    vector<vector<Int>> A(H,vector<Int>(W));
    REP(i,H)REP(j,W)cin>>A[i][j];

    for(int i1=0;i1<H-1;i1++){
        for(int i2=i1+1;i2<H;i2++){
            for(int j1=0;j1<W-1;j1++){
                for(int j2=j1;j2<W;j2++){
                    if(A[i1][j1]+A[i2][j2]<=A[i2][j1]+A[i1][j2])continue;
                    cout<<"No\n";exit(0);
                }
            }
        }
    }
    cout<<"Yes\n";
}