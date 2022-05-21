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
ll get_nCr(ll n,ll r){
    ll res=1; 
    for(ll i=1;i<=r;i++){
        res=res*(n-i+1)/i;
    }
    return res;
}
using namespace std;
int main(void){
    ll N,P;cin>>N>>P;
    vector<ll> A(N);
    REP(i,N)cin>>A[i];
    ll n1=0,n2=0;
    REP(i,N){
        if(A[i]%2==0)n2++;
        else n1++;
    }
    cout<<"n1:"<<n1<<" n2:"<<n2<<"\n";
    ll cnt=0;
    REPS(i,n1){
        if(i%2==1){
            cnt+=get_nCr(n1,i);
        }
    }

    cout<<cnt*n2<<"\n";
}