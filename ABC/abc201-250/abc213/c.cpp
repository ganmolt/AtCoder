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
    Int H,W,N;cin>>H>>W>>N;
    vector<pair<pair<Int,Int>,Int>> v(N);
    REP(i,N){
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second=i;
    }
    sort(v.begin(),v.end(),[&](const auto l, const auto r){
        return l.first.first < r.first.first;
    });
    //REP(i,N)cout<<v[i].first.first<<" ";cout<<"\n";
    Int nX=0;Int zX=INF;
    REP(i,N){
        //cout<<i<<": "<<"zx: "<<zX<<" v[i]: "<<v[i].first.first<<"\n";
        if(v[i].first.first==zX){
            v[i].first.first=nX;
        }
        else{
            zX=v[i].first.first;
            v[i].first.first=++nX;
        }
    }
    //REP(i,N)cout<<v[i].first.first<<" ";cout<<"\n";
    sort(v.begin(),v.end(),[&](const auto l, const auto r){
        return l.first.second < r.first.second;
    });
    Int nY=0;Int zY=INF;
    REP(i,N){
        if(v[i].first.second==zY){
            v[i].first.second=nY;
        }
        else{
            zY=v[i].first.second;
            v[i].first.second=++nY;
        }
    }
    sort(v.begin(),v.end(),[&](const auto l, const auto r){
        return l.second < r.second;
    });

    REP(i,N){
        cout<<v[i].first.first<<" "<<v[i].first.second<<"\n";
    }
}