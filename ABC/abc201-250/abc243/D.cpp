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
int main(void){
    Int N,X;cin>>N>>X;
    string S;cin>>S;

    deque<char> que;
    REP(i,N){
        if(S[i]=='U'){
            if(!que.empty()&&que.front()!='U')que.pop_front();
            else que.push_front('U');
        }
        else if(S[i]=='L'){
            que.push_front('L');
        }
        else if(S[i]=='R'){
            que.push_front('R');
        }
        else{}
    }
    while(!que.empty()){
        auto r=que.back();que.pop_back();
        //cout<<r<<" ";
        if(r=='L') X*=2;
        else if(r=='R') X=X*2+1;
        else X/=2;
    }
    cout<<X<<"\n";
}