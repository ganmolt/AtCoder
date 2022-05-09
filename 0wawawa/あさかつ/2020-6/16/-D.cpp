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
class COM{
    vi fact;
    vi inv;
    ll N;
    ll mod;
public:
    COM(ll n,ll m=MOD){
        N=n;fact.resize(N+1);inv.resize(N+1);
        mod=m;
    }
    ll power(ll a, ll b){
        ll res=1;
        while(b>0){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    }
    void __init__(){
        fact[0]=1;
        REPS(i,N){fact[i]=fact[i-1]*i%mod;}
        inv[N]=power(fact[N],mod-2);
        RREPS(i,N){inv[i-1]=inv[i]*i%mod;}
    }
    ll nCr(ll n,ll r){
        return fact[n]*inv[n-r]*inv[r]%mod;
    }
};
//-----------------------------------------
int main(void){
    COM com(2200);
    com.__init__();
    ll K,N;cin>>N>>K;
    REPS(i,K){
        cout<<com.nCr(K-1,i-1)*com.nCr(N-K+1,i)%MOD<<"\n";
    }
}