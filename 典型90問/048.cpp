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
    vector<int> a(n),b(n);REP(i,n)cin>>a[i]>>b[i];
    priority_queue<pair<Int,pair<int,int>>> que;//point, ind, v
    REP(i,n)que.push({b[i],{i,1}});
    Int ans=0;
    while(!que.empty()){
        if(k==0)break;
        auto [p,pp]=que.top();que.pop();
        auto [i,v]=pp;
        ans+=p;
        if(v==1)que.push({a[i]-b[i],{i,2}});
        if(v==2);//continue;
        //cout<<p<<" ";
        k--;
    }
    cout<<ans<<"\n";
}