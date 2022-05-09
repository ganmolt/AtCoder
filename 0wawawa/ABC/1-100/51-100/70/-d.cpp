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
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
//-----------------------------------------
#define ifYN(x) cout<<(x?"Yes":"No")<<"\n" 
#define dcml(n) fixed<<setprecision(n)

 
ll GCD(ll a,ll b) { return b ? GCD(b,a%b) : a; } 
ll LCM(ll a,ll b) { return a/GCD(a,b)*b; } 
ll Factorial(ll n){ ll m=1;while(n>=1)m*=n--;return m; } 
ll modPow(ll x,ll n,ll mod=MOD){ 
    return (!n?1:!n%2?modPow(x*x,n/2,mod)%mod:x%mod*modPow(x,n-1,mod)%mod); 
} 



using namespace std;
//-------------------------------------------
typedef pair<ll,ll> P;
struct Edge{ll to,dist;};
ll N; ll d[100000];
vector<Edge> G[100000];

void dijkstra(ll u){
    REP(i,100000)d[i]=INF;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({0,u});
    while(!que.empty()){
        auto r=que.top();que.pop();
        if(r.first>=d[r.second])continue;//更新不可
        d[r.second]=r.first;//更新

        for(Edge& e: G[r.second]){
            ll dist=d[r.second]+e.dist;
            if(dist>=d[e.to])continue;//更新不可
            que.push({dist,e.to});//更新
        }
    }
}
int main(void){
    ll N;cin>>N;
    ll a,b,c;
    REP(i,N-1){
        cin>>a>>b>>c;
        a--,b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    ll Q,K;cin>>Q>>K;
    K--;
    dijkstra(K);
    ll x[Q],y[Q];
    REP(i,Q){
        cin>>x[i]>>y[i];
    }
    REP(i,Q){
        x[i]--,y[i]--;
        cout<<d[x[i]]+d[y[i]]<<"\n";
    }
}