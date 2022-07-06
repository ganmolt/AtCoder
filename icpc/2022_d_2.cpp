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
    while(true){
        int n;cin>>n;
        if(!n)break;
        vector<int> b(n);REP(i,n)cin>>b[i];
        
        priority_queue<int> que;
        REP(i,n)que.push(b[i]);
        Int ans=0;
        while(que.size()>=3){
            int r[3];
            REP(i,3){r[i]=que.top();que.pop();}
            int m=min({r[0],r[1],r[2]});
            REP(i,3)r[i]-=m;
            ans+=m;
            REP(i,3){
                if(r[i]==0)continue;
                que.push(r[i]);
            }
        }
        cout<<ans<<"\n";
    }
}