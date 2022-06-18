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
    vector<int> G[n];
    vector<int> d(n,0);
    REP(i,m){
        int k;cin>>k;
        int p;
        REP(j,k){
            int a;cin>>a;a--;
            if(j==0){
                p=a;
                continue;
            }
            G[p].push_back(a);
            d[a]++;
            p=a;
        }
    }
    // REP(i,n)cout<<i<<": "<<d[i]<<"\n";
    queue<int> que;
    for(int i=0;i<n;i++){
        if(d[i]==0)que.push(i);
    }
    //REP(i,n)cout<<i<<": "<<d[i]<<"\n";
    //cout<<"--------\n";
    vector<int> ans;
    while(!que.empty()){
        int r=que.front();que.pop();
        ans.push_back(r);
        for(auto to:G[r]){
            d[to]--;
            if(d[to]==0)que.push(to);
            //REP(i,n)cout<<i<<": "<<d[i]<<"\n";
        }
    }
    if(ans.size()==n){
        YES;
    }
    NO;
    /*
    cout<<que.size()<<"\n";
    for(auto r:ans){
        cout<<r<<" ";
    }cout<<"\n";*/
}