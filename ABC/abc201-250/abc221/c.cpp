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
Int f(vector<int> v){
    Int ret=0;
    REP(i,v.size()){
        ret=ret*10+v[i];
    }
    return ret;
}
int main(void){
    string S;cin>>S;
    vector<int> v0;
    REP(i,S.size()){
        v0.push_back(S[i]-'0');
    }
    sort(v0.begin(),v0.end(),greater<int>());
    vector<int> v[2];
    REP(i,v0.size()){
        if(i<=1){
            if(i==0)v[0].push_back(v0[i]);
            if(i==1)v[1].push_back(v0[i]);
        }
        else{
            if(f(v[0])<f(v[1])){
                v[0].push_back(v0[i]);
            }else{
                v[1].push_back(v0[i]);
            }
        }
    }
    Int ans[2]={0,0};
    REP(i,2){
        REP(j,v[i].size()){
            ans[i]=ans[i]*10+v[i][j];
        }
    }
    cout<<ans[0]*ans[1]<<"\n";
}