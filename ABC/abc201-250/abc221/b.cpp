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
    string s,t;cin>>s>>t;
    int n=s.size();
    int state=0;int tmpidx=-1;char tmp;
    REP(i,n){
        if(s[i]==t[i])continue;
        else{
            if(state==0){
                state=1;
                tmp=s[i];
                tmpidx=i;
            }else if(state==1){
                if(i-tmpidx>1){
                    cout<<"No\n";
                    exit(0);
                }
                s[tmpidx]=s[i];
                s[i]=tmp;
                state=2;
            }else{
                cout<<"No\n";
                exit(0);
            }
        }
    }
    if(s==t)cout<<"Yes\n";
    else cout<<"No\n";
}