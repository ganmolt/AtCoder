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
    int n,qn;cin>>n>>qn;
    vector<int> x(n),y(n);REP(i,n)cin>>x[i]>>y[i];
    vector<int> q(qn);REP(i,qn)cin>>q[i],q[i]--;
    //45'回転
    vector<Int> X(n),Y(n);REP(i,n)X[i]=x[i]-y[i],Y[i]=x[i]+y[i];
    Int xm=1e9,xM=0,ym=1e9,yM=0;
    REP(i,n){
        chmin(xm,X[i]);
        chmax(xM,X[i]);
        chmin(ym,Y[i]);
        chmax(yM,Y[i]);
    }

    REP(i,qn){
        cout<<max(
            max(
                abs(X[q[i]]-xm),abs(xM-X[q[i]])
            ),max(
                abs(Y[q[i]]-ym),abs(yM-Y[q[i]])
            )
        )<<"\n";
    }
}