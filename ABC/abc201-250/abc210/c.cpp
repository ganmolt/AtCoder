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
    Int N,K;cin>>N>>K;
    vector<Int> c(N);
    REP(i,N)cin>>c[i];

    map<Int,Int> m;
    REP(i,K)m[c[i]]++;
    Int ans,tmp=0;
    for(auto r:m){
        tmp++;
    }
    ans=tmp;
    for(Int i=0;i+K<N;i++){
        if(m[c[i]]==1){
            tmp--;
            m[c[i]]--;
        }else{
            m[c[i]]--;
        }

        if(m[c[i+K]]==0){
            tmp++;
            chmax(ans,tmp);
            m[c[i+K]]++;
        }else{
            m[c[i+K]]++;
        }
    }
    cout<<ans<<"\n";
}