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
    vector<ll> A(N);
    REP(i,N)cin>>A[i];

    ll jdg=0;//-1,0,1
    ll cnt=1;
    REPS(i,N){
        if(i==N)break;
        if(jdg==0){//増加減少が決まっていない
            if(A[i-1]==A[i])continue;
            if(A[i-1]<A[i])jdg=1;
            else jdg=-1;
        }
        else{//決まっていたら
            if(
                (jdg==-1&&A[i-1]<A[i])||(jdg==1&&A[i-1]>A[i])
            ){//増加減少が変わったら
                jdg=0;
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}