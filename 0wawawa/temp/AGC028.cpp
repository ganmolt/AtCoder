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
    ll N,M;cin>>N>>M;
    string S,T;cin>>S>>T;
    S.insert(0,"0");
    T.insert(0,"0");
    ll L=LCM(N,M);
    ll idx_S=-1,idx_T=-1;
    ll i=1,j=1;
    while(true){
        idx_S=(i-1)*(L/N)+1;
        idx_T=(j-1)*(L/M)+1;
        //cout<<idx_S<<" "<<idx_T<<"\n";
        if(idx_S>L||idx_T>L)break;
        //cout<<S[idx_S]<<" "<<T[idx_T]<<"\n";
        
        if(idx_S==idx_T){
            if(S[i]==T[j]){
                i++,j++;
            }
            else{
                cout<<-1<<"\n";
                exit(0);
            }
        }

        else if(idx_S<idx_T)i++;
        else if(idx_S>idx_T)j++;


    }
    /*
    REPS(i,N){
        cout<<(i-1)*M+1<<" ";
    }cout<<"\n";
    REPS(i,M){
        cout<<(i-1)*N+1<<" ";
    }cout<<"\n";*/
    cout<<L<<"\n";
}
