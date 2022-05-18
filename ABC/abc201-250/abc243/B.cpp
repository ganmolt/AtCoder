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
    vector<Int> A(N),B(N);
    REP(i,N)cin>>A[i];
    REP(i,N)cin>>B[i];

    vector<Int> v1;//indも要素も同じ
    REP(i,N){
        if(A[i]==B[i])v1.push_back(A[i]);
    }
    sort(v1.begin(),v1.end());
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<Int> v2;//要素が同じ
    set_intersection(A.begin(),A.end(),
                    B.begin(),B.end(),
                    back_inserter(v2) );
    //REP(i,v2.size())cout<<v2[i]<<" ";cout<<"\n";
    vector<Int> v3;//要素は同じだけどindは違う
    set_difference(v2.begin(),v2.end(),
                    v1.begin(),v1.end(),
                    back_inserter(v3));
    //REP(i,v3.size())cout<<v3[i]<<" ";cout<<"\n";

    cout<<v1.size()<<"\n";
    cout<<v3.size()<<"\n";
}