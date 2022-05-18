//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
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
int leftWin(char l, char r){
    if( (l=='G'&&r=='C')||
        (l=='C'&&r=='P')||
        (l=='P'&&r=='G')
    ){
        return 1;
    }else if(l==r){
        return 0;
    }else{
        return -1;
    }
}
int main(void){
    Int N,M;cin>>N>>M;
    char A[2*N][M];
    REP(i,N*2){
        REP(j,M){
            cin>>A[i][j];
        }
    }

    priority_queue<pair<Int,pair<Int,Int>>,
                    vector<pair<Int,pair<Int,Int>>>,
                    greater<pair<Int,pair<Int,Int>>>
                    > que;
    REP(i,N*2)que.push({0,{0,i}});//round(+), winpoint(-), idx(+)
    REP(m,M){
        REP(i,N){
            auto r1=que.top();que.pop();
            auto r2=que.top();que.pop();
            int i1=r1.second.second;
            int i2=r2.second.second;
            char gcp1=A[i1][m];
            char gcp2=A[i2][m];
            int res=leftWin(gcp1,gcp2);
            if(res==1){
                //leftwin
                que.push({m+1,{r1.second.first-1,i1}});
                que.push({m+1,{r2.second.first,i2}});
            }else if(res==0){
                //draw
                que.push({m+1,{r1.second.first,i1}});
                que.push({m+1,{r2.second.first,i2}});
            }else{
                //leftlose
                que.push({m+1,{r1.second.first,i1}});
                que.push({m+1,{r2.second.first-1,i2}});
            }
        }

    }
    REP(i,N*2){
        auto r=que.top();que.pop();
        cout<<r.second.second+1<<"\n";
    }
}