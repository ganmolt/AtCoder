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
    ll X;cin>>X;
    ll n=100000;
    REP(j,n){
        FOR(i,j+1,n){
            if(X%(i-j)==0){
                //cout<<"Y";
                ll i2=i*i;ll j2=j*j;
                ll i5=i2*i2*i,j5=j2*j2*j;
                //cout<<i5<<" "<<j5;
                if(i5-j5>X)break;
                if(i5-j5==X){
                    cout<<i<<" "<<j<<"\n";
                    return 0;
                }
                if(i5+j5==X){
                    cout<<i<<" "<<-j<<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}