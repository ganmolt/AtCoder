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
int main(void){
    ll H,W;cin>>H>>W;
    char m[H][W];
    char M[H][W];
    REP(i,H){
        REP(j,W){
            cin>>m[i][j];
        }
    }
    ll K=8;
    ll dy[K]={-1,-1,-1,0,0,1,1,1};
    ll dx[K]={-1,0,1,-1,1,-1,0,1};
    REP(i,H){
        REP(j,W){
            if(m[i][j]=='#'){
                M[i][j]='#';
                continue;
            }
            ll cnt=0;
            REP(k,K){
                ll x=j+dx[k],y=i+dy[k];
                if(0<=x&&x<W and 0<=y&&y<H){
                    if(m[y][x]=='#')cnt++;
                }
            }
            M[i][j]=cnt+'0';
        }
    }
    REP(i,H){
        REP(j,W){
            cout<<M[i][j]<<(j==W-1?"\n":"");
        }
    }
}