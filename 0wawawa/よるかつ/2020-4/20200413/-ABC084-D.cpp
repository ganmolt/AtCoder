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
bool isPrime(int num){
    if(num<2) return false;
    else if(num==2)return true;
    else if(num%2==0)return false; // 偶数はあらかじめ除く

    double sqrtNum=sqrt(num);
    for(int i=3;i<=sqrtNum;i+=2){
        if(num%i==0)return false;
    }
    // 素数である
    return true;
}

int main(void){
    ll N=100010;
    bool f[N+1];f[0]=false;f[1]=false;FOR(i,2,N)f[i]=true;
    FOR(i,2,N+1){
        if(f[i])for(ll j=i+i;j<100000;j+=i)f[j]=false;
    }
    
    ll asum[N+1];asum[0]=0;
    REPS(i,N){
        asum[i]=asum[i-1];
        if(i%2==1&&f[i]&&f[(i+1)/2])asum[i]++;
    }
    //REPS(i,100)cout<<i<<":"<<asum[i]<<" ";



    ll Q;cin>>Q;
    vector<pair<ll,ll>> que;
    ll l,r;
    REP(i,Q){
        cin>>l>>r;
        que.push_back(make_pair(l,r));
    }
    REP(i,Q){
        ll L=que[i].first,R=que[i].second;
        cout<<asum[R]-asum[L-1]<<"\n";
    }
}