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
const ll MOD=998244353LL;
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
ll S;
map<vi,ll> mp;
ll solve(vi v){
    decltype(mp)::iterator it=mp.find(v);
    if(it!=mp.end())return it->second;
    else{
        ll ans2=0;
        for(auto r:v){
            ans2+=r;
        }
        if(ans2==S)mp[v]=1;
        for(int bit=0;bit<(1<<v.size());bit++){
            vi v2;
            for(int i=0;i<v.size();i++){
                if(bit&(1<<i)){
                    v2.push_back(i);
                }
            }
            mp[v]+=solve(v2);
        }
    }
    return 0;
}
int main(void){
    ll N;cin>>N>>S;
    vector<ll> A(N);
    REP(i,N)cin>>A[i];
    ll ans=0;
    for(int bit=0;bit<(1<<N);bit++){
        vi v;
        for(int i=0;i<N;i++){
            if(bit&(1<<i)){
                v.push_back(i);
            }
        }
        ans+=solve(v)%MOD;
    }
    cout<<ans<<"\n";
}
