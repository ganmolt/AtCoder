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
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
Int pow(Int x, Int n, Int mod=MOD){
    Int ret=1;
    while(n>0){
        if(n&1)ret=ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}
//-----------------------------------------
int main(void){
    Int n;cin>>n;
    vector<Int> a(n);REP(i,n)cin>>a[i];
    map<Int,Int> m;
    REP(i,n){
        m[a[i]]++;
    }
    /*
    FOR(i,1,n/2+1){
        cout<<i*2-(n%2==0)<<":"<<m[i*2-(n%2==0)]<<" ";
    }*/
    FOR(i,1,n/2+1){
        //cout<<a[i*2-(i%2==0)]<<":"<<m[a[i*2-(i%2==0)]]<<" ";
        if(m[a[i*2-(n%2==0)]]==2)continue;
        cout<<"0\n";
        exit(0);
    }
    if(n%2==1 && m[0]!=1){
        cout<<"0\n";
        exit(0);
    }

    /*
    if(n%2==1){
        REP(i,n){
            if(i%2==1)a[i]--;
            if(i==a[i])continue;
            NO;
        }
    }else{
        REP(i,n){
            if(i%2==0)a[i]--;
            if(i==a[i])continue;
            NO;
        }
    }*/
    cout<<pow(2,n/2)<<"\n";
}