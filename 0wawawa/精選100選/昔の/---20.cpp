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
    ll N;cin>>N;
    vector<ll> A(N);
    REP(i,N)cin>>A[i];
    vector<ll> B(N);
    REP(i,N)cin>>B[i];
    vector<ll> C(N);
    REP(i,N)cin>>C[i];
    sort(ALLv(A));
    sort(ALLv(B));
    sort(ALLv(C));
    ll cnt[N];
    REP(i,N){
        ll aidx=upper_bound(ALLv(A),B[i])-A.begin();
        //cout<<aidx<<" ";
        if(aidx<0)continue;//aがきめられない
        cnt[i]=(aidx);
    }
    /*ll acnt[N+1];acnt[0]=0;
    REPS(i,N)acnt[i]=acnt[i-1]+cnt[i-1];*/
    /*REPS(i,N)cout<<i<<":"<<cnt[i]<<"\n";*/
    ll ans=0;
    REP(i,N){
        ll bidx=upper_bound(ALLv(B),C[i])-B.begin()-1;
        while(bidx>=0){
            //cout<<cnt[bidx]<<" ";
            ans+=cnt[bidx];
            bidx--;
        }
    }cout<<"\n";
    cout<<ans<<"\n";
}