//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"correct\n",exit(0)
#define NO cout<<"incorrect\n",exit(0)
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
    int n;cin>>n;
    vector<char> a[n];
    REP(i,n){
        REP(j,n){
            char c;cin>>c;
            a[i].push_back(c);
        }
    }

    REP(i,n){
        FOR(j,i+1,n){
            if(a[i][j]=='W'){
                if(a[j][i]=='L')continue;
                NO;
            }
            if(a[i][j]=='D'){
                if(a[j][i]=='D')continue;
                NO;
            }
            if(a[i][j]=='L'){
                if(a[j][i]=='W')continue;
                NO;
            }
        }
    }
    YES;
}
