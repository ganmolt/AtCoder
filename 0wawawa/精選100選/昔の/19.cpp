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
    ll d;cin>>d;//環状線の全長
    ll n;cin>>n;//店舗の個数
    ll m;cin>>m;//注文の個数
    vector<ll> stores(n+1);
    stores[0]=0;REPS(i,n-1)cin>>stores[i];stores[n]=d;
    vector<ll> k(m);
    REP(i,m)cin>>k[i];
    sort(ALLv(stores));
    //REP(i,n+1)cout<<stores[i]<<" ";cout<<"\n";
    ll ans=0;
    REP(i,m){
        ll lidx=lower_bound(ALLv(stores),k[i])-stores.begin();
        //cout<<"lidx:"<<stores[lidx]<<"\n";
        ll d0=abs(k[i]-stores[lidx-1]);
        ll d1=abs(stores[lidx]-k[i]);
        //cout<<d0<<" "<<d1<<"\n";
        ans+=min(d0,d1);
    }
    cout<<ans<<"\n";
}