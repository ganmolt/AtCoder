//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
//-----------------------------------------
#define dcml(n) fixed<<setprecision(n)
using namespace std;
ll Y[4]={-1,0,1,0};
ll X[4]={0,1,0,-1};
int main(void){
    ll H,W;cin>>H>>W;
    char s[H][W];
    REP(i,H)REP(j,W)cin>>s[i][j];
    //cout<<"\n\n";
    //WREP(i,H,j,W)cout<<s[i][j]<<(i==W-1?"\n":" ");
    bool OK=true;
    WREP(i,H,j,W){
        if(s[i][j]=='.')continue;
        bool isWall=false;
        REP(k,4){
            if(!(0<=i+Y[k]&&i+Y[k]<H&&0<=j+X[k]&&j+X[k]<W)){
                //cout<<":::"<<i+Y[k]<<" "<<j+X[k]<<"\n";
                continue;
            }
            if(s[i+Y[k]][j+X[k]]=='#'){//壁があれば
                isWall=true;
                break;
            }
        }if(!isWall){
            //cout<<i<<" "<<j<<"\n";
            OK=false;
        }
    }
    cout<<(OK?"Yes":"No")<<"\n";
}