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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
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
    vi fact, inv;
    ll N, mod;
public:
    COM(ll n,ll m=MOD):N(n),mod(m){
        fact.resize(N+1);inv.resize(N+1);
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
        return fact[n]*inv[n-r]%mod*inv[r]%mod;
    }
};
//-----------------------------------------
int main(void){
    ll N,P;cin>>N>>P;
    vi A(N);
    REP(i,N){
        cin>>A[i];
        A[i]%=2;
    }
    ll cnt_0=0,cnt_1=0;
    for(int bit=0;bit<(1<<N);bit++){
        for(int i=0;i<N;i++){
            if(bit&(1<<i)){
                cnt_1++;
            }else{
                cnt_0++;
            }
        }
    }
    cout<<"1:"<<cnt_1<<", 0:"<<cnt_0<<"\n";

    COM c(N,INF);
    ll s_0=0;
    REPS(i,cnt_0){
        s_0+=c.nCr(N,i);
    }
    ll s_1=0;
    REPS(i,cnt_1){
        if(i%2==P)s_1+=c.nCr(N,i);
    }
    cout<<s_0<<" "<<s_1<<"\n";
    cout<<s_0*s_1<<"\n";
}
