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
    int a,b,x,y;cin>>a>>b>>x>>y;
    a--;b--;
    vector<pair<int,int>> G[200];

    REP(i,100){
        G[i].push_back({i+100,x});
        G[i+100].push_back({i,x});
    }
    REP(i,99){
        G[i].push_back({i+1,y});
        G[i+1].push_back({i,y});

        G[i+100].push_back({i+101,y});
        G[i+101].push_back({i+100,y});

        G[i+1].push_back({i+100,x});
        G[i+100].push_back({i+1,x});
    }
    int d[200];REP(i,200)d[i]=1e9;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    d[a]=0;
    que.push({0,a});
    while(!que.empty()){
        auto r=que.top();que.pop();
        //r.first: dist
        //r.second: to
        for(auto to:G[r.second]){
            //to.first: to
            //to.second: dist
            if(d[to.first]<=r.first+to.second)continue;

            d[to.first]=r.first+to.second;
            que.push({d[to.first],to.first});
        }
    }
    /*
    REP(i,100){
        cout<<i<<"a: "<<d[i]<<", b: "<<d[i+100]<<"\n";
    }*/
    cout<<d[b+100]<<"\n";


}