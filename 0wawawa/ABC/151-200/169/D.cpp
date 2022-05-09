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
ll GCD(ll a,ll b) { return b ? GCD(b,a%b) : a; }
ll LCM(ll a,ll b) { return a/GCD(a,b)*b; }
ll Factorial(ll n){ ll m=1;while(n>=1)m*=n--;return m; }
ll pow(ll a, ll b, ll mod=INF){
    ll res=1;
    while(b>0){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll getDigit(ll num){
    ll digit=0; 
    while(num!=0){num/=10;digit++;}
    return digit;
}
//-----------------------------------------
int main(void){
    ll N;cin>>N;
    bool P[1000001];
    REP(i,1000001)P[i]=true;P[0]=P[1]=false;
    FOR(i,2,1000001){
        if(P[i]==true){
            for(ll k=2;i*k<1000001;k++){
                P[i*k]=false;
            }
        }
    }

    //REP(i,1000)cout<<P[i]<<" ";

    ll cnt=0;
    REP(i,1000001){
        if(!P[i])continue;
        for(ll k=i;N>=k&&N%k==0;k*=i){
            //cout<<k<<"\n";
            N/=k;
            cnt++;
        }
    }
    if(N>=1000000)cnt++;
    cout<<cnt<<"\n";
}
