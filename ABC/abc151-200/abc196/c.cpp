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
    string s;cin>>s;
    Int N=0;for(int i=0;i<s.size();i++)N=N*10+(s[i]-'0');
    int nN=(s.size()+1)/2;
    string subs=s.substr(0,nN);
    //cout<<subs<<"\n";
    Int n=0;for(int i=0;i<subs.size();i++)n=n*10+(subs[i]-'0');
    Int cnt=0;
    for(Int i=1;i<=n;i++){
        if(i<10){
            if(i*10+i<=N)cnt++;
        }
        else if(i<100){
            if(i*100+i<=N)cnt++;
        }
        else if(i<1000){
            if(i*1000+i<=N)cnt++;
        }
        else if(i<10000){
            if(i*10000+i<=N)cnt++;
        }
        else if(i<100000){
            if(i*100000+i<=N)cnt++;
        }
        else if(i<1000000){
            if(i*1000000+i<=N)cnt++;
        }
    }
    cout<<cnt<<"\n";
}