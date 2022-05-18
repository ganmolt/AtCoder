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
    int n;cin>>n;
    vector<Int> a(n),b(n);
    REP(i,n)cin>>a[i]>>b[i];

    vector<pair<Int,Int>> ab(n);REP(i,n)ab[i].first=a[i],ab[i].second=b[i];
    sort(ab.begin(),ab.end());
    sort(ab.begin()+1,ab.end(),[&](auto l,auto r){
        return l.second < r.second;
    });
    Int ans=INF;
    chmin(ans,ab[0].first+ab[0].second);
    chmin(ans,max(ab[0].first,ab[1].second));

    
    sort(ab.begin(),ab.end(),[&](auto l,auto r){
        return l.second < r.second;
    });
    sort(ab.begin()+1,ab.end());
    chmin(ans,ab[0].first+ab[0].second);
    chmin(ans,max(ab[1].first,ab[0].second));

    cout<<ans<<"\n";
}