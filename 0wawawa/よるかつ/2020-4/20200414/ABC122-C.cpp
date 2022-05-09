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
struct ASUM{
    bool lA=false;
    ll cnt=0;
};
int main(void){
    ll N,Q;cin>>N>>Q;
    string S;cin>>S;

    ll asum[N+1]={};
    REPS(i,N){
        asum[i]=asum[i-1];
        if(S[i-1]=='A'&&S[i]=='C'){
            asum[i]++;
        }
    }
    pair<ll,ll> q[Q];REP(i,Q)cin>>q[i].first>>q[i].second;

    REP(i,Q){
        ll l=q[i].first,r=q[i].second;
        //cout<<S[r-1]<<"r:"<<asum[r]<<" "<<S[l-1]<<"l:"<<asum[l]<<"\n";
        cout<</*"res:"<<*/asum[r-1]-asum[l-1]<<"\n";
    }
}
