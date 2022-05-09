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
int N;
bool ok[1100];
//-----------------------------------------
int main(void){
    cin>>N;
    for(int a=1;4*a+3*a+3<=1000;a++){
        for(int b=1;4*a*b+3*a+3*b<=1000;b++){
            ok[4*a*b+3*a+3*b]=true;
        }
    }
    int cnt=0;
    REP(i,N){
        int s;cin>>s;
        if(!ok[s])cnt++;
    }
    cout<<cnt<<"\n";
}