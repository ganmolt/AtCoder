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

//-----------------------------------------
int main(void){
    ll H,W,A,B;
    cin>>H>>W>>A>>B;

    if(B>H/2){
        cout<<-1<<"\n";
        exit(0);
    }
    if(A>W/2){
        cout<<-1<<"\n";
        exit(0);
    }

//A!=0,B==0
    if(A!=0&&B==0)
    REP(i,H){
        REP(j,W){
            cout<<(j<A)<<(j==W-1?"\n":"");
        }
    }

//A==0,B!=0
    if(A==0&&B!=0)
    REP(i,H){
        REP(j,W){
            cout<<(i<B)<<(j==W-1?"\n":"");
        }
    }

//A!=0,B!=0
    if(A!=0&&B!=0)
    REP(i,H){
        REP(j,W){
            cout<<((i<B)^(j<A))<<(j==W-1?"\n":"");
        }
    }

//A==0,B==0
    if(A==0&&B==0)
    REP(i,H){
        REP(j,W){
            cout<<0<<(j==W-1?"\n":"");
        }
    }

}