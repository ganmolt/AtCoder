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
ll GCD(ll a,ll b) { return b ? GCD(b,a%b) : a; }
ll LCM(ll a,ll b) { return a/GCD(a,b)*b; }
ll Factorial(ll n){ ll m=1;while(n>=1)m*=n--;return m; }
ll modPow(ll x,ll n,ll mod=MOD){
    return (!n?1:!n%2?modPow(x*x,n/2,mod)%mod:x%mod*modPow(x,n-1,mod)%mod);
}

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
 
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fac[i]  = fac[i-1]*i%MOD;
        inv[i]  = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
 
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/


int main() {
    ll N,K;cin>>N>>K;
    ll M=(N+1)*N/2;
    ll m=K*(K-1)/2;
    ll l=(M-m);
    ll ans=(M+m)*l/2;
    cout<<M<<" "<<m<<" "<<l<<":";
    cout << ans << endl;
}