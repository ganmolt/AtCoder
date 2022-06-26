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
    vector<int> u(m),v(m);REP(i,m)cin>>u[i]>>v[i],u[i]--,v[i]--;
    vector<pair<int,int>> G[n+1];//to, cost
    REP(i,m){
        if(u[i]==-1){
            G[v[i]].push_back({n,1});
            G[n].push_back({v[i],1});
        }else{
            G[u[i]].push_back({v[i],1});
            G[v[i]].push_back({u[i],1});
        }
    }
    int d[n+1];REP(i,n+1)d[i]=1e9;

    priority_queue<
    pair<int,int>, 
    vector<pair<int,int>>, 
    greater<pair<int,int>>
    > que;

    que.push({0,0});
    d[0]=0;
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(d[r.second]<r.first)continue;
        for(auto to:G[r.second]){
            if(d[to.first]>r.first+to.second){
                d[to.first]=r.first+to.second;
                que.push({d[to.first],to.first});
            }
        }
    }
    //================================================
    int d2[n+1];REP(i,n+1)d2[i]=1e9;

    priority_queue<
    pair<int,int>, 
    vector<pair<int,int>>, 
    greater<pair<int,int>>
    > que2;

    que2.push({0,n-1});
    d2[n-1]=0;
    while(!que2.empty()){
        auto r=que2.top();que2.pop();
        if(d2[r.second]<r.first)continue;
        for(auto to:G[r.second]){
            if(d2[to.first]>r.first+to.second){
                d2[to.first]=r.first+to.second;
                que2.push({d2[to.first],to.first});
            }
        }
    }

    int ans=d[n-1];
    REP(i,n){
        int a=min(ans,d[n]+d2[i]);
        a=min(a,d[i]+d2[n]);
        if(a==1e9)a=-1;
        cout<<a<<(i==n-1?"\n":" ");
    }
}
