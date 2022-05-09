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
    ll A,B,C;cin>>A>>B>>C;
    ll cnt=0;
    while(!(A==B&&B==C)){
        if(A==B&&A>C){C+=2;cnt++;}
        else if(A==C&&A>B){B+=2;cnt++;}
        else if(C==B&&B>A){A+=2;cnt++;}

        else if(A==B&&A<C){A++;B++;cnt++;}
        else if(A==C&&A<B){A++;C++;cnt++;}
        else if(C==B&&B<A){B++;C++;cnt++;}

        else{
            if(A<B&&B<C){A++;B++;cnt++;}
            else if(B<C&&C<A){C++;B++;cnt++;}
            else if(C<A&&A<B){A++;C++;cnt++;}

            else if(B>C&&C>A){C++;A++;cnt++;}
            else if(C>A&&A>B){A++;B++;cnt++;}
            else if(A>B&&B>C){B++;C++;cnt++;}

        }
    }
    cout<<cnt<<"\n";
    
}