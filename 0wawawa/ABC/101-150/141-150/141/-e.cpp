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
#define ifYN(x) cout<<(x?"Yes":"No")<<"\n" 
#define dcml(n) fixed<<setprecision(n)

 
ll GCD(ll a,ll b) { return b ? GCD(b,a%b) : a; } 
ll LCM(ll a,ll b) { return a/GCD(a,b)*b; } 
ll Factorial(ll n){ ll m=1;while(n>=1)m*=n--;return m; } 
ll modPow(ll x,ll n,ll mod=MOD){ 
    return (!n?1:!n%2?modPow(x*x,n/2,mod)%mod:x%mod*modPow(x,n-1,mod)%mod); 
} 



using namespace std;
//-------------------------------------------
typedef pair<ll,ll> P;
int main(void){
    ll N;string S;
    cin>>N>>S;
    ll ans=0;
    REP(i,N-1){
        string s1=S.substr(0,i);
        FOR(j,i+1,N){
            string s2=S.substr(j,N-j);
            cout<<s1<<" "<<s2<<"\n";
            ll cnt=0;
            ll n=min(N-1-i,N-j);
            REP(k,n){
                if(s1[k]!=s2[k]){break;}
                else{cnt++;}
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<"\n";
}