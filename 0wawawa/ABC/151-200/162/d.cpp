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
    ll N;string S;cin>>N>>S;
    ll cnt=0;
    ll n1=0,n2=0,n3=0;
    REP(i,N){
        if(S[i]=='R')n1++;
        else if(S[i]=='G')n2++;
        else n3++;
    }
    cnt=n1*n2*n3;
    REP(i,N){
        for(ll k=1;i+2*k<N;k++){
           if(S[i]!=S[i+k]&&S[i+k]!=S[i+2*k]&&S[i+2*k]!=S[i])cnt--;
        }
    }
    cout<<cnt<<"\n";
}