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
int main(void){
    string S;cin>>S;
    ll N=S.size();
    vi a(N);
    REP(i,N){
        a[i]=(S[i]-'0');
    }
    ll ans=0;
    for(ll bit=0;bit<(1<<N);bit++){
        ll sm=0;ll n=0;
        REP(i,N){
            if(bit&(1<<i)){
                //cout<<"+";
                sm+=n;
                n=a[i];
            }
            else{
                n*=10;
                n+=a[i];
            }
            //cout<<a[i];
            if(i==N-1)sm+=n;
        }
        //cout<<"="<<sm<<"\n";
        ans+=sm;
    }
    cout<<ans/2<<"\n";
}
