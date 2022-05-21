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
    ll N,D;cin>>N>>D;
    ll X[N][D];
    WREP(i,N,j,D)cin>>X[i][j];
    ll cnt=0;
    REP(i1,N-1){
        FOR(i2,i1+1,N){
            ll l0=0;
            //if(i1==i2)continue;
            REP(j,D){
                l0+=(X[i1][j]-X[i2][j])*(X[i1][j]-X[i2][j]);
            }
            ld d0=sqrt(l0);
            if(d0==(ll)(d0))cnt++;
        }
    }
    cout<<cnt<<"\n";
}