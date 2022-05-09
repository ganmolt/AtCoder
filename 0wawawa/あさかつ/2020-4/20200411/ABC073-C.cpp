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
    priority_queue<ll,vector<ll>,less<ll>> que;
    ll N;cin>>N;

    ll A;ll mx=0;
    REP(i,N){
        cin>>A;
        que.push(A);
    }
    que.push(-1);
    ll cnt=0;ll z=0;ll c=0;
    REP(i,N+1){
        auto r=que.top();que.pop();
        if(r==-1){
            if(c%2==1)cnt++;
            break;
        }
        if(i==0||z==r)c++;
        else{
            if(c%2==1){
                cnt++;
            }
            c=1;
        }
        z=r;
    }
    cout<<cnt<<"\n";
}