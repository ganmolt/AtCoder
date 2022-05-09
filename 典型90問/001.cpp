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
    Int N,L;
    cin>>N>>L;
    Int K;cin>>K;
    vector<Int> A(N+1);
    REP(i,N)cin>>A[i];A[N]=L;
    for(int i=N;i>0;i--){
        A[i]-=A[i-1];
    }

    //REP(i,N+1)cout<<A[i]<<" ";cout<<"\n";
    Int lb=1,ub=L;Int m;
    while(ub-lb>1){
        m=(lb+ub)/2;
        //cout<<"m: "<<m<<"\n";
        Int tmp=0;Int cnt=0;
        REP(i,N+1){
            tmp+=A[i];
            if(tmp>=m){
                //cout<<tmp<<",";
                tmp=0;
                cnt++;
            }/*
            else if(i==N){
                tmp=0;
                cnt++;
                break;
            }*/
        }
        //cout<<"cnt: "<<cnt<<" ";
        if(cnt>=K+1)lb=m;
        else ub=m;
        tmp=0,cnt=0;
        //cout<<"lb: "<<lb<<", "<<"ub: "<<ub<<"\n";
    }
    cout<<lb<<"\n";
}