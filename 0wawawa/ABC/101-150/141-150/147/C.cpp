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
    ll n;cin>>n;
    typedef pair<int, bool> shogen;
    vector<shogen> p[n];
    REP(i,n){
        ll a;cin>>a;
        int x;bool y;
        REP(j,a){
            cin>>x>>y;x--;
            p[i].push_back(make_pair(x,y));
        }
    }
    int ans=0;
    bool flag;int cnt;
    for(int bit=0;bit<(1<<n);bit++){//集合を決め打ち
        flag=true;cnt=0;
        for(int i=0;i<n;i++){
            if(bit & 1<<i){cnt++;//決め打たれた正直者
                for(auto r:p[i]){//各証言
                    int x=r.first;
                    bool y=r.second;
                    if((bit & (1<<x)) && y)continue;
                    if(!(bit & 1<<x) && !y)continue;
                    flag=false;
                    break;
                }
                if(!flag)break;
            }
        }
        if(flag){
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<"\n";
}