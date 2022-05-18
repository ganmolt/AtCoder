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
    int n,q;cin>>n>>q;
    vector<int> G[n];
    vector<int> c(q),d(q);

    REP(i,n-1){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);G[b].push_back(a);
    }

    REP(i,q){
        cin>>c[i]>>d[i];c[i]--;d[i]--;
    }
    int b[n];REP(i,n)b[i]=0;b[0]=-1;
    queue<int> que;que.push(0);
    while(!que.empty()){
        auto r=que.front();que.pop();
        for(auto to:G[r]){
            if(b[to]==0){
                b[to]=-b[r];
                que.push(to);
            }
        }
    }

    REP(i,q){
        if(b[c[i]]==b[d[i]])cout<<"Town\n";
        else cout<<"Road\n";
    }
}
