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
vector<Int> cls(330000);

int main(void){
    int N;cin>>N;
    cls.resize(N);
    Int A[N];REP(i,N)cin>>A[i];
    int Q;cin>>Q;
    Int B[Q];REP(i,Q)cin>>B[i];
    //クラス分け
    sort(A,A+sizeof(A)/sizeof(A[0]));
    for(int i=N-1;i>=1;i--)cls[i]=(A[i]+A[i-1]+0.5)/2;//切り上げ
    cls[0]=0;

    //lowerboundでクラス分け可能
    REP(i,Q){
        Int idx=lower_bound(cls.begin(),cls.end(),B[i])-cls.begin()-1;
        cout<<abs(A[idx]-B[i])<<"\n";
    }
}
/*lower_boundのとき、begin()からend()までみると値を入れていないところまで見られる
今回、cls(330000)のままresize(N)をしなかったところ、lb=330000が返ってき続けた。
*/