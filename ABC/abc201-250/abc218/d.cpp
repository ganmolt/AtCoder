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
    Int N;cin>>N;
    vector<pair<Int,Int>> v(N);
    REP(i,N){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    Int ans=0;
    REP(i,N){
        REP(j,N){
            v[i].first<v[j].first&&v[i].second<v[j].second&&
            binary_search(v.begin(),v.end(),make_pair(v[i].first,v[j].second))&&
            binary_search(v.begin(),v.end(),make_pair(v[j].first,v[i].second))&&
            ans++;
        }
    }
    cout<<ans<<"\n";
}