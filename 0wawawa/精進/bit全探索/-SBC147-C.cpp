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
typedef pair<ll,ll> P;
int main(void){
    ll N;cin>>N;
    vector<P> A[N];
    REP(i,N){
        ll k;cin>>k;
        REP(j,k){
            P p;int x,y;cin>>x>>y;x--;
            p=make_pair(x,y);
            A[j].push_back(p);
        }
    }
    ll ans=0;ll cnt=0;bool is;
    ll o[N];REP(i,N)o[i]=-1;
    for(int bit=0;bit<(1<<N);bit++){
        is=true;
        REP(i,N){
            cnt=0;
            if(bit&1<<i){
                for(auto r:A[i]){
                    if(o[r.first]==0)continue;//嘘つき
                    if(o[r.first]==-1){
                        o[r.first]=r.second;
                        cnt++;
                    }
                    else if(o[r.first]==1&&r.second==1)continue;
                    else if(o[r.first]!=r.second){
                        is=false;
                        break;
                    }
                }
            }else{
                o[i]=0;
            }
            if(!is)break;
        }
        if(is){
            REP(i,N)if(o[i]==-1)cnt++;
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<"\n";
}