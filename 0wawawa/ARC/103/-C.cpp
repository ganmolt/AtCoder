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
#define dcml(n) fixed<<setprecision(n)
//CONST
//------------------------------------------
const ll INF=1010000000000000017LL;
const ll MOD=1000000007LL;
const ld EPS=1e-12;
const ld PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define  FORS(i,m,n) for(ll (i)=(m);   (i)<=(n); (i)++)
#define  RFOR(i,m,n) for(ll (i)=(n)-1; (i)>=(n); (i)--)
#define RFORS(i,m,n) for(ll (i)=(n);   (i)>(n);  (i)--)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
#define WREPS(i,in,j,jn) REPS(i,in)REPS(j,jn)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    ll N;cin>>N;
    vector<ll> v(N);
    REP(i,N)cin>>v[i];
    ll n=N/2;
    vi v0(n),v1(n);
    REP(i,N){
        if(i%2==0)v0[i/2]=v[i];
        else v1[i/2]=v[i];
    }
//REP(i,n)cout<<v0[i]<<" ";cout<<"\n";
//REP(i,n)cout<<v1[i]<<" ";cout<<"\n";

    map<ll,ll> m0, m1;
    REP(i,n){
        m0[v0[i]]++;
        m1[v1[i]]++;
    }
    ll M0=0,M1=0;
    ll i0=0,i1=0;

    ll S0=0,S1=0;
    ll Si0=0,Si1=0;
    REP(i,110000){
        if(M0<m0[i]){
            S0=M0;Si0=i0;
            M0=m0[i];i0=i;
        }
        if(M1<m1[i]){
            S1=M1;Si1=i1;
            M1=m1[i];i1=i;
        }
    }
    ll a11=0,a12=0,a21=0;
    if(i0==i1) a11=INF;
    else a11=N-M0-M1;

    if(i0==Si1) a12=INF;
    else a12=N-M0-S1;

    if(Si0==i1) a21=INF;
    else a21=N-S0-M1;

    cout<<min(a11,min(a12,a21))<<"\n";
}