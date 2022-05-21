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
ll N,M,X;
struct book{
    ll cost;
    vi A;
};
vector<book> books(12);

bool ok(vi v){
    for(auto r:v){
        //cout<<r<<" ";
        if(r>=X)continue;
        return false;
    }//cout<<"\n";
    return true;
}
ll dfs(int i,ll sm, vi v){
    ll ret=INF;
    if(i==N){//全部決め終わったら
        //if(ok(v))cout<<sm<<" ";
        if(ok(v)) return ret=sm;
        else return ret=INF;
    }
    vi vuse=v;//cout<<i<<":";
    for(int j=0;j<M;j++){
        vuse[j]+=books[j].A[i];
        //cout<<vuse[j]<<" ";
    }//cout<<"\n";
    ret=min(
    dfs(i+1,sm+books[i].cost,vuse),//使う
    dfs(i+1,sm,v)//使わない
    );
    return ret;
}
int main(void){
    cin>>N>>M>>X;
    REP(i,N){
        cin>>books[i].cost;
        REP(i,M){
            ll a;cin>>a;
            books[i].A.push_back(a);
        }
    }
    vi v(M,0);
    ll ans=dfs(0,0,v);
    cout<<(ans==INF?-1:ans)<<"\n";
}

