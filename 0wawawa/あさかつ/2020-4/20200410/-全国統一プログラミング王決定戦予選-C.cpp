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
#define dcml(n) fixed<<setprecision(n)
using namespace std;
int main(void){
    ll N;cin>>N;
    typedef pair<ll,pair<ll,ll>> P;
    priority_queue<P,vector<P>,greater<P>> que;
    ll A,B;
    REP(i,N){
        cin>>A>>B;
        que.push(make_pair(A+B,make_pair(A,B)));

    }   
    ll ans1=0,ans2=0;
    REP(i,N){
        auto r=que.top();que.pop();
        if(i%2==0){
            //takahashi
            ans1+=r.second.first;
        }
        else{
            //aoki
            ans2=r.second.second;
        }
    }
    cout<<ans1-ans2<<"\n";
}