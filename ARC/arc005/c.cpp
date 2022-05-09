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
    int h,w;cin>>h>>w;
    char c[h*w];int sx,sy,gx,gy;
    REP(i,h)REP(j,w){
        cin>>c[i*w+j];
        if(c[i*w+j]=='s')sx=i,sy=j;
        if(c[i*w+j]=='g')gx=i,gy=j;
    }
    vector<pair<int,int>> G[h*w];
    REP(i,h)REP(j,w){
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        REP(k,4){
            int nx=i+dx[k],ny=j+dy[k];
            if(false
            ||nx<0
            ||h<=nx
            ||ny<0
            ||w<=ny
            )continue;
            G[i*w+j].push_back({(c[nx*w+ny]=='#'),nx*w+ny});
        }
        
    }
    int d[300000];REP(i,300000)d[i]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > que;
    que.push({0,sx*w+sy});d[sx*w+sy]=0;
    while(!que.empty()){
        auto r=que.top();que.pop();
        //cout<<r.second<<"("<<r.first<<")"<<":";
        for(auto to:G[r.second]){
            
            if(d[to.second]>r.first+to.first){
                //cout<<to.second<<"";
                //cout<<"("<<r.first<<"+"<<to.first<<")";
                d[to.second]=r.first+to.first;
                //cout<<to.second<<","<<d[to.second]<<"\n";
                que.push({d[to.second],to.second});
                //cout<<",";
            }
            
        }//cout<<"\n";
    }
    cout<<(d[gx*w+gy]>2?"NO\n":"YES\n");
}