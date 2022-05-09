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
    ll N,K;cin>>N>>K;
    vector<ll> p(N+1);
    REPS(i,N)cin>>p[i];
    vi Asum(N+1);Asum[0]=0;REPS(i,N)Asum[i]=Asum[i-1]+p[i];
    ll ans=0;
    REPS(i,N-K+1){
        //cout<<Asum[i+K-1]-Asum[i-1]<<"\n";
        ans=max(ans,Asum[i+K-1]-Asum[i-1]);
    }
    cout<<dcml(10)<<(ans+(1*K))/2.0<<"\n";
}