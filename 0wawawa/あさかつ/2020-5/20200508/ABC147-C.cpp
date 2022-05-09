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
#define vb vector<bool>
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
typedef pair<ll,bool> P;
int main(void){
    ll N;cin>>N;
    vector<P> A[N];
    REP(i,N){
        ll k;cin>>k;
        REP(j,k){
            ll x;bool y;cin>>x>>y;x--;
            A[i].push_back(make_pair(x,y));
        }
    }
    ll ans=0;
    for(int bit=0;bit<(1<<N);bit++){//正直者の仮定
        ll cnt=0;bool ok=true;
        REP(i,N){
            if(bit&1<<i){//i番目が正直者であると仮定する
                //i番目のヒトの証言
                for(auto r:A[i]){
                    //xijは正直者or不親切なヒト　と　bitが一致するか
                    if(r.second){//xijが正直者だと話して
                        if(bit & 1<<r.first);//仮定したのと一致すればok
                        else{ok=false;break;}
                    }else{
                        if(!(bit & 1<<r.first));
                        else{ok=false;break;}
                    }
                }
                cnt++;
            }
        }
        if(ok)ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
}