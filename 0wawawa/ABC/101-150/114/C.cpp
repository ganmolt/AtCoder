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
ll D,N;
ll cnt=0;
vi a(3);
void dfs(ll sm,ll d=1,ll c3=0, ll c5=0, ll c7=0){
    ll x=sm%10;
    (x==3?c3:x==5?c5:c7)++;
    if(sm>N)return;
    if(d>D)return;
    if(c3>0 and c5>0 and c7>0)cnt++;

    sm*=10;
    for(auto r:a){
        dfs(sm+r,d+1,c3,c5,c7);
    }
    return;
}
int main(void){
    cin>>N;
    D=getDigit(N);
    a={3,5,7};
    for(auto r:a){
        dfs(r);
    }
    cout<<cnt<<"\n";
}