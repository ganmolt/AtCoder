//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const Int INF=1010000000000000017LL;
const Int MOD=998244353LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
struct COM{
    Int n, mod;
    vector<Int> fac,finv,inv;

    COM(Int n, Int m): n(n), mod(m){
        fac.resize(n+1);
        finv.resize(n+1);
        inv.resize(n+1);
        COMinit();
    }
    // テーブルを作る前処理
    void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++){
            fac[i] = fac[i-1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }

    // 二項係数計算
    Int nCk(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};
//-----------------------------------------
int main(void){
    Int n;cin>>n;
    COM com(300000,MOD);

    Int ans=1;
    ans = n*n;
    ans = (ans * com.fac[n-1]) % MOD;
    ans = (ans * com.fac[n-1]) % MOD;
    ans = ans * com.nCk(n*n, 2*n-1) % MOD;
    ans = ans * com.fac[(n-1) * (n-1)] % MOD;
    cout<<(com.fac[n*n]-ans+MOD)%MOD<<"\n";
    //cout<<com.fac[n-1]<<","<<com.fac[(n-1)*(n-1)]<<","<<com.nCk(n*n,2*n-1)<<","<<n*n<<"\n";
}