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
    map <pair<Int,Int>,Int> dd;
    for(int i=-200;i<=200;i++)
    for(int j=-200;j<=200;j++){
        dd[{i,j}]=(i-j)*(i-j);
    }
    map<Int,Int> m;
    REP(i,N){
        Int a;cin>>a;
        m[a]++;
    }/*
    for(int i=-200;i<200;i++){
        if(m[i]!=0)
            cout<<i<<":"<<m[i]<<" ";
    }*/
    map<pair<Int,Int>,Int> mm;
    for(int i=-200;i<=200-1;i++){
        for(int j=i+1;j<=200;j++){
            mm[make_pair(i,j)]=m[i]*m[j];
        }
    }
    /*
    for(int i=-200;i<=200-1;i++){
        for(int j=i+1;j<=200;j++){
            if(mm[{i,j}]!=0)
            cout<<i<<","<<j<<":"<<mm[{i,j}]<<" ";
        }
    }*/
    
    Int ans=0;
    for(Int i=-200;i<=200-1;i++){
        for(Int j=i+1;j<=200;j++){
            if(mm[{i,j}]!=0){
                ans+=dd[{i,j}]*mm[make_pair(i,j)];
                //cout<<i<<","<<j<<":"<<dd[{i,j}]<<" ";
            }
        }
    }
    cout<<ans<<"\n";
}