//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long int
#define Double long double
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
Int N;
vector<Int> G[110000];

Int dist[110000];
void maxDist(Int from){
    for(Int i=0;i<N;i++){
        dist[i]=INF;
    }
    queue<Int> que;
    que.push(from);
    dist[from]=0;

    
    while(!que.empty()){
        //for(Int i=0;i<N;i++)cout<<dist[i]<<" ";cout<<"\n";
        Int pos=que.front();que.pop();
        //cout<<"from:"<<pos<<" to:";for(Int t:G[pos])cout<<t<<" ";cout<<"\n";
        for(Int to:G[pos]){
            if(dist[to]==INF){
                dist[to]=dist[pos]+1;
                que.push(to);
            }
        }
    }
}
int main(void){
    cin>>N;
    Int a,b;
    REP(i,N-1){
        cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    maxDist(0);//to,length
    Int M1=0;Int maxid1=-1;
    //REP(i,N)cout<<dist[i]<<" ";cout<<"\n";
    REP(i,N)chmax(M1,dist[i]);
    REP(i,N){
        if(dist[i]==M1){
            //cout<<"i:"<<i<<"\n";
            maxid1=i;
        }
    }
    maxDist(maxid1);
    Int M2=0;
    REP(i,N)chmax(M2,dist[i]);
    //REP(i,N)cout<<dist[i]<<" ";cout<<"\n";
    cout<<M2+1<<"\n";
}