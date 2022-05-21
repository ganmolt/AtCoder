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

 
using namespace std;
//-------------------------------------------
typedef pair<ll,ll> P;
bool operator<(const P& p1, const P& p2){
    if(p1.first!=p2.first)return p1.first<p2.first;
    else return p1.second<p2.second;
};
int main(void){
    ll N,M;cin>>N>>M;
    priority_queue<P,vector<P>> que;
    ll A,B;
    REP(i,N){
        cin>>A>>B;
        que.push({B,A});
    }
    ll ans=0;
    REP(i,M){
        //cout<<i+1<<"日目:\n";
        auto r=que.top();que.pop();
        //cout<<r.first<<"円が"<<r.second<<"にもらえる、"<<M-i<<"日後まで"<<"\n";
        if(r.second>M-i){/*cout<<"だめ！\n";*/continue;}
        //cout<<"+"<<r.first<<"円;\n";
        ans+=r.first;
    }
    cout<<ans<<"\n";
}
