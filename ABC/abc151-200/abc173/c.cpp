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
    int h,w,k;cin>>h>>w>>k;
    vector<vector<char>> c(h,vector<char>(w));REP(i,h)REP(j,w)cin>>c[i][j];

    Int ans=0;
    for(int bit=0;bit<(1<<h+w);bit++){
        vector<vector<char>> tmp(c.begin(),c.end());
        /*REP(i,h){
            REP(j,w){
                cout<<c[i][j]<<" ";;
            }cout<<"\n";
        }*/
        for(int i=0;i<h;i++){
            if(1<<i&bit){
                REP(j,w)tmp[i][j]='*';
            }
        }
        for(int i=h;i<h+w;i++){
            if(1<<i&bit){
                REP(j,h)tmp[j][i-h]='*';
            }
        }
        Int cnt=0;
        REP(i,h)REP(j,w){
            if(tmp[i][j]=='#')cnt++;
        }
        if(cnt==k)ans++;
    }
    cout<<ans<<"\n";
}