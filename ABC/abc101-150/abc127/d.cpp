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
    int n,m;cin>>n>>m;
    vector<Int> a(n);
    REP(i,n)cin>>a[i];

    vector<Int> b(m),c(m);
    REP(i,m){
        cin>>b[i]>>c[i];
    }

    vector<pair<Int,Int>> v;
    REP(i,n)v.push_back({a[i],1});
    REP(i,m){
        v.push_back({c[i],b[i]});
    }
    sort(v.begin(),v.end(),greater<pair<Int,Int>>());
    
    Int ans=0;
    int i=0;
    while(n>0){
        if(v[i].second<=n){
            ans+=v[i].second*v[i].first;
            n-=v[i].second;
        }else{
            ans+=v[i].first*n;
            n=0;
        }
        i++;
    }
    cout<<ans<<"\n";
}


