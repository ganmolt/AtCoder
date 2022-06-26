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
    int n;string s;cin>>n>>s;
    vector<Int> w(n);REP(i,n)cin>>w[i];

    vector<Int> BIG,sml;
    REP(i,n){
        if(s[i]=='1')BIG.push_back(w[i]);
        else sml.push_back(w[i]);
    }
    sort(BIG.begin(),BIG.end());
    sort(sml.begin(),sml.end());
    //cout<<"BIG: ";for(auto r:BIG)cout<<r<<" ";cout<<"\n";
    //cout<<"sml: ";for(auto r:sml)cout<<r<<" ";cout<<"\n";

    Int ans=0;
    w.push_back(-1);w.push_back(INF);
    REP(i,n+2){
        //cout<<w[i]<<": ";
        Int Bcnt=BIG.end()-lower_bound(BIG.begin(),BIG.end(),w[i]);
        //cout<<"B: "<<Bcnt<<", ";
        
        Int scnt=lower_bound(sml.begin(),sml.end(),w[i])-sml.begin();
        //cout<<"s: "<<scnt;
        //cout<<"\n";
        chmax(ans,Bcnt+scnt);
    }
    cout<<ans<<"\n";
}