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
    ll N;cin>>N;
    vector<ll> H(N);
    REP(i,N)cin>>H[i];
    if(H[0]>=1)H[0]-=1;
    REPS(i,N-1){
        if(H[i-1]<H[i])H[i]-=1;
    }
    bool OK=true;
    REPS(i,N-1){
        if(H[i-1]<=H[i])continue;
        else{
            //cout<<i<<"\n\n";
            OK=false;
            break;
        }
    }
    //REP(i,N)cout<<H[i]<<" ";
    if(OK)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}