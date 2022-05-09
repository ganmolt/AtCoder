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
ll R,S,P;
ll RSP(char a,char b){
    if(a=='r'&&b=='s')return R;
    if(a=='s'&&b=='p')return S;
    if(a=='p'&&b=='r')return P;
    return 0;
}
char rsp[3]={'r','s','p'};
int main(void){
    ll N,K;cin>>N>>K;
    cin>>R>>S>>P;
    string T;cin>>T;
    pair<ll,ll> dp[3][100001];
    dp[0][0]=make_pair(RSP('r',T[0]),0);
    dp[1][0]=make_pair(RSP('s',T[0]),1);
    dp[2][0]=make_pair(RSP('p',T[0]),2);
    REP(k,3){
        cout<<dp[k][0].first<<" "<<char(rsp[dp[k][0].second]-'a'+'A')<<"\n";
    }
    ll M;
    REPS(i,N){
        M=max(dp[0][i-1].first,max(dp[1][i-1].first,dp[2][i-1].first));
        REP(k,3){
            if(i-K>=0) if(dp[k][i-K].second==k)dp[k][i]=make_pair(M,4);
            dp[k][i]=make_pair(M+RSP(rsp[k],T[i]),k);
        }
        REP(k,3){
            cout<<dp[k][i].first<<" "<<char(rsp[dp[k][i].second]-'a'+'A')<<"\n";
        }
    }
    cout<<M<<"\n";
}