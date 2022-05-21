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

ll N;ll ans=0;
vi a;
void exhaustiveSearch(ll i, ll n, ll sm){
    if(i==N){
        sm+=n;
        ans+=sm;
        return;
    }

    exhaustiveSearch(i+1,a[i],sm+n);//+
    exhaustiveSearch(i+1,n*10+a[i],sm);//not +


}
int main(void){
    string S;cin>>S;
    N=S.size();
    a.resize(N);
    REP(i,N){
        a[i]=(S[i]-'0');
    }
    exhaustiveSearch(0,0,0);
    cout<<ans/2<<"\n";
    
}
