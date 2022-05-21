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
//ll M=100000000000;
int main(void){
    ll N;cin>>N;
    ll cnt=0;
    for(ll i=1;i*i*i<=N;i++){
        for(ll j=i;i*j*j<=N;j++){
            ll c=N/(i*j);
            if(j>c)break;
            cnt+=c-j+1;
        }
    }
    cout<<cnt<<"\n";
    /*
    ll m=sqrt(M);
    vi X[m+1];
    ll rm=sqrt(m);
    REPS(i,rm){
        FORS(j,i,m){
            if(i*j>m)break;
            X[i*j].push_back(j);
        }
    }
    REPS(i,m){
        cout<<i<<":";
        for(auto r:X[i])cout<<r<<" ";
        cout<<"\n";
    }

    ll N;cin>>N;
    ll cnt=0;
    REPS(i,m){
        ll c=N/i;
        if(i>c)break;
        //cout<<i<<","<<j<<":"<<c-j+1<<"\n";
        for(auto r:X[i]){
            cout<<"(r,c,sm)=("<<r<<","<<c<<","<<c-r+1<<") ";
            cnt+=c-r+1;
        }cout<<"\n";
    }
    cout<<cnt<<"\n";
    */
    
}