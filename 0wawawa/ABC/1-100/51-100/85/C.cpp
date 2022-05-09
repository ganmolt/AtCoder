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
    ll N,Y;cin>>N>>Y;
    if(Y/N==10000){cout<<N<<" "<<"0 0\n";exit(0);}
    if(Y/N==5000){cout<<"0 "<<N<<" 0\n";exit(0);}
    if(Y/N==1000){cout<<"0 0 "<<N<<"\n";exit(0);}
    REP(i,N+1){//10000
        if(i>N)break;
        ll l1=i*10000;
        if(l1>Y)break;
        REP(j,N+1){//5000
            if(i+j>N)break;
            ll l2=l1+j*5000;
            if(l2>Y)break;
            REP(k,N+1){//1000
                if(i+j+k>N)break;
                if(i+j+k!=N)continue;
                ll l3=l2+k*1000;
                if(l3>Y)break;
                if(l3==Y){
                    cout<<i<<" "<<j<<" "<<k<<"\n";
                    exit(0);
                }
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<"\n";
}