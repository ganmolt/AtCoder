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
    Int N,K;cin>>N>>K;
    vector<Int> A(N);
    REP(i,N)cin>>A[i];
    vector<Int> s;
    vector<pair<Int,Int>> a;
    REP(i,N){
        if(i<K)s.push_back(A[i]);
        else a.push_back({A[i],i});
    }
    //cout<<"s: ";
    //REP(i,s.size())cout<<s[i]<<" ";cout<<"\n";
    sort(a.begin(),a.end());
    vector<Int> a2(a.size());
    REP(i,a.size()){
        a2[i]=a[i].first;
    }
    //REP(i,a.size())cout<<"a:"<<a[i].first<<" ";cout<<"\n";

    Int ans=INF;
    REP(i,K){
        Int idx=upper_bound(a2.begin(),a2.end(),s[i] )-a2.begin();
        //cout<<"s:"<<s[i]<<" "<<"i: "<<idx<<"\n";
        if(idx==a2.size())continue;
        //cout<<"idx:"<<a[idx].second<<" ";
        //cout<<a[idx].second-i<<"\n";
        if(ans>a[idx].second-i)ans=a[idx].second-i;
    }
    cout<<(ans==INF?-1:ans)<<"\n";
}