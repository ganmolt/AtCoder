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
vi lunlunN={1,2,3,4,5,6,7,8,9};
void lunlun(ll k){
    ll cnt=10;
    REP(i,k){
        if(cnt>=k)return;
        ll p=lunlunN[i]%10;
        if(p>=1)lunlunN.push_back(lunlunN[i]*10+p-1);
        lunlunN.push_back(lunlunN[i]*10+p);
        if(p<=8)lunlunN.push_back(lunlunN[i]*10+p+1);
        cnt++;
    }
}
int main(void){
    ll K;cin>>K;
    lunlun(K);
    sort(ALLv(lunlunN));
    cout<<lunlunN[K-1]<<"\n";
}