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
    Int n,x,y;cin>>n>>x>>y;

    Int ans=0;
    queue<pair<Int,pair<Int,Int>>> que;//個数, level, 色r==1:b==0,  
    que.push({1,{n,1}});
    while(!que.empty()){
        auto r=que.front();que.pop();
        Int m=r.first;
        Int l=r.second.first;
        Int c=r.second.second;
        if(l==1&&c==0){
            ans+=m;
            continue;
        }
        if(l==1&&c==1){
            continue;
        }
        if(c==1){
            que.push({m*1,{l-1,1}});
            que.push({m*x,{l,0}});
        }else{
            que.push({m*1,{l-1,1}});
            que.push({m*y,{l-1,0}});
        }
        
    }
    cout<<ans<<"\n";
}