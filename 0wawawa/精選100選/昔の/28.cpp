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
struct Edge{
    ll to;
};
vector<Edge> G[100];
ll N,d[100];
typedef pair<ll,ll> P;
void bfs(ll i){
    REP(i,N)d[i]=-1;
    queue<P> que;
    que.push(make_pair(0ll,0ll));
    d[0]=0;
    while(!que.empty()){
        P q=que.front();que.pop();
        //cout<<q.first+1<<":";
        for(auto r:G[q.first]){
            if(d[r.to]!=-1){
                //cout<<"continue";
                continue;
            }
            d[r.to]=q.second+1;
            //cout<<r.to+1<<" ";
            que.push(make_pair(r.to,q.second+1));
        }//cout<<"\n";
    }
}
int main(void){
    cin>>N;
    REP(i,N){
        ll idx,k;cin>>idx>>k;
        REP(j,k){
            ll to;cin>>to;to--;
            G[i].push_back({to});
        }
    }
    bfs(0);
    REP(i,N){
        cout<<i+1<<" "<<d[i]<<"\n";
    }
}