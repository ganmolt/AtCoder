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
    Int N;cin>>N;
    int c1[N];
    int c2[N];
    REP(i,N){
        int c,p;
        cin>>c>>p;
        if(c==1){
            c1[i]=p;
            c2[i]=0;
        }
        if(c==2){
            c1[i]=0;
            c2[i]=p;
        }
    }
    int AsC1[N+1];
    int AsC2[N+1];
    AsC1[0]=AsC2[0]=0;
    for(int i=1;i<=N;i++){
        AsC1[i]=AsC1[i-1]+c1[i-1];
        AsC2[i]=AsC2[i-1]+c2[i-1];
    }
    for(int i=1;i<=N;i++){
        //cout<<AsC1[i]<<" "<<AsC2[i]<<"\n";
    }
    //1-idx
    Int Q;cin>>Q;
    queue<pair<int,int>> que;
    
    REP(i,Q){
        int l,r;cin>>l>>r;
        que.push({l,r});
    }
    while(!que.empty()){
        auto r=que.front();que.pop();
        cout<<AsC1[r.second]-AsC1[r.first-1]<<" "<<AsC2[r.second]-AsC2[r.first-1]<<"\n";
    }
}
