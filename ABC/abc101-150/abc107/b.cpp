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
    int h,w;cin>>h>>w;
    char c[h][w];REP(i,h)REP(j,w)cin>>c[i][j];

    bool by[h],bx[w];REP(i,h)by[i]=false;REP(i,w)bx[i]=false;
    REP(i,h){
        bool ok=true;
        REP(j,w){
            //cout<<i<<","<<j<<":"<<c[i][j]<<",";
            if(c[i][j]=='#')ok=false;
        }//cout<<"\n";
        by[i]=ok;
    }
    
    REP(j,w){
        bool ok=true;
        REP(i,h){
            if(c[i][j]=='#')ok=false;
        }
        bx[j]=ok;
    }

    REP(i,h){
        if(by[i]==true)continue;
        REP(j,w){
            if(bx[j]==true)continue;
            cout<<c[i][j];
        }cout<<"\n";
    }
}