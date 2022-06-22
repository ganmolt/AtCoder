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
Int dp[1100000];
int main(void){
    Int a,n;cin>>a>>n;
    REP(i,1100000)dp[i]=INF;

    dp[n]=0;
    queue<int> que;
    que.push(n);
    while(!que.empty()){
        auto r=que.front();que.pop();
        //if(dp[r]==1e9)continue;
        if(r%a==0){
            if(chmin(dp[r/a],dp[r]+1))que.push(r/a);
        }

        if(r>=10){
            string s_n=to_string(r);
            string s_n2;
            for(int i=1;i<s_n.size();i++)s_n2.push_back(s_n[i]);
            s_n2.push_back(s_n[0]);
            if(s_n2[0]=='0')continue;
            Int n2=stoll(s_n2);
            
            if(chmin(dp[n2],dp[r]+1))que.push(n2);
        }
    }
    cout<<(dp[1]==INF?-1:dp[1])<<"\n";

}