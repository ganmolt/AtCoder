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
    ll N;cin>>N;
    /*  1猛暑:   max>=35
        2真夏日: 30<=max<35
        3夏日:   25<=max<30
        4真冬日: 0>max

        5熱帯夜: 25<=min

        6冬日:   min<0,max>=0
        
    */
    typedef pair<ld,ld> P;
    P p[N];
    REP(i,N)cin>>p[i].first>>p[i].second;

    ll c1,c2,c3,c4,c5,c6;c1=c2=c3=c4=c5=c6=0;//cnt
    REP(i,N){
        ld M=p[i].first,m=p[i].second;
        if(M>=35)c1++;
        else if(30<=M and M<35)c2++;
        else if(25<=M and M<30)c3++;
        else if(M<0)c4++;

        if(25<=m)c5++;

        if(m<0 and M>=0)c6++;
    }
    printf("%lld %lld %lld %lld %lld %lld\n",c1,c2,c3,c5,c6,c4);
}   