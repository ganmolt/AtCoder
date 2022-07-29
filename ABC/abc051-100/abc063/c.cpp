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
bool b[110][11000];
int main(void){
    int n;cin>>n;
    vector<int> a(n);REP(i,n)cin>>a[i];


    priority_queue<pair<int,int>> que;
    que.push({0,0});

    int ans=0;
    while(true){
        auto r=que.top();que.pop();
        if(-r.first>n)break;

        if(b[-r.first][r.second])continue;
        cout<<r.first<<","<<r.second<<"\n";
        b[-r.first][r.second]=true;
        que.push({r.first-1, r.second});
        que.push({r.first-1, r.second+a[-r.first]});
        if(r.second%10)chmax(ans,r.second);
    }
    cout<<ans<<"\n";
}