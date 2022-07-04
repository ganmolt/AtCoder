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
    int n;cin>>n;
    char c[n][n];REP(i,n)REP(j,n)cin>>c[i][j];
    int a[n][n];
    REP(i,n)REP(j,n)a[i][j]=c[i][j]-'0';
    /*REP(i,n){
        REP(j,n)cout<<a[i][j];cout<<"\n";
    }*/
    Int ans=0;

    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};

    REP(i,n){
        REP(j,n){
            REP(k,8){
                Int tmp=0;
                int DX=dx[k];
                int DY=dy[k];
                int x=i,y=j;
                REP(l,n){
                    //cout<<"("<<x<<","<<y<<")=>";
                    tmp*=10;
                    tmp+=a[x][y];
                    x=(x+DX+n)%n;
                    y=(y+DY+n)%n;
                }//cout<<"\n";
                chmax(ans,tmp);
            }
            
        }
    }
    cout<<ans<<"\n";
}