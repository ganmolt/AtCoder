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
    int N,K;cin>>N>>K;
    vector<int> v(N);REP(i,N)cin>>v[i];
    REP(i,N)if(v[i]==0){
        cout<<N<<"\n";
        exit(0);
    }
    Int length=0;
    for(Int l=0,r=0,xx=1;l<N;){
        while(r<N&&xx*v[r]<=K){
            xx*=v[r++];
            //cout<<l<<","<<r<<":"<<xx<<" \n";
        }
        chmax(length,r-l);
        if(r==N)break;
        if(l==r){
            xx*=v[r++];
            //cout<<l<<","<<r<<":"<<xx<<" \n";
        }
        xx/=v[l++];
        //cout<<l<<","<<r<<":"<<xx<<" \n";

    }
    cout<<length<<"\n";
}