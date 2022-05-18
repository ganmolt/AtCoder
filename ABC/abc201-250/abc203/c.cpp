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
    Int n,k;cin>>n>>k;
    vector<pair<Int,Int>> v(n);
    REP(i,n){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    map<Int,Int> m;
    REP(i,n)m[v[i].first]+=v[i].second;
    Int ans=0;
    while(k>0){
        auto itNxt=m.upper_bound(ans);
        if(itNxt==m.end()){
            ans+=k;
            break;
        }
        Int nxt=itNxt->first;
        if(k>=(nxt-ans)){
            k-=(nxt-ans);
            ans+=(nxt-ans);
            k+=itNxt->second;
        }
        else{
            ans+=k;
            k=0;
        }
    }
    cout<<ans<<"\n";
}