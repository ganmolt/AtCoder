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
    ll a[N];REP(i,N)a[i]=S[i]-'0';

    ll n=0;ll cnts[2019];REP(i,2019)cnts[i]=0;cnts[0]=1;
    REP(i,N){
        n=(n*10+a[i])%2019;
        cout<<n<<" ";
        cnts[n]++;
    }cout<<"\n";
    ll cnt=0;
    REP(i,2019){
        cout<<(cnts[i]>=2?to_string(cnts[i])+" ":"");
        cnt+=cnts[i]*(cnts[i]-1)/2;
    }
    cout<<cnt<<"\n";
}