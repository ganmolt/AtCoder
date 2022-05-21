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
vector<ll> G[101000];
int main(void){
    ll N,M;cin>>N>>M;
    vector<ll> H(N);
    REP(i,N)cin>>H[i];
    
    REP(i,M){
        ll a,b;
        cin>>a>>b; a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll cnt=0;
    REP(i,N){
        bool f=true;//一番大きいか
        for(auto r:G[i]){
            //r : 各展望台からいける展望台
            if(H[i]<=H[r]){
                f=false;
                break;
            }
        }
        if(f)cnt++;
    }
    cout<<cnt<<"\n";
}