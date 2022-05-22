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
    Int n,l;cin>>n>>l;
    vector<Int> a(n);REP(i,n)cin>>a[i];

    priority_queue<Int,vector<Int>,greater<Int>> que;
    REP(i,n){
        que.push(a[i]);
        l-=a[i];
    }
    if(l>0){
        que.push(l);
    }
    Int ans=0;
    while(que.size()>=2){
        auto r1=que.top();que.pop();
        auto r2=que.top();que.pop();
        ans+=r1+r2;
        que.push(r1+r2);
    }
    
    cout<<ans<<"\n";
}