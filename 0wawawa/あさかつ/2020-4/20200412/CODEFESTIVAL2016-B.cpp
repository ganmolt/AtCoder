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
    ll N,A,B;cin>>N>>A>>B;
    string S;cin>>S;
    ll cnt=0,cntB=0;
    REP(i,N){
        if(S[i]=='a'){
            //A+B
            if(cnt<A+B){
                cnt++;
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
        else if(S[i]=='b'){
            //A+B & B以内
            if(cnt<A+B && cntB<B){
                cnt++;cntB++;
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
        else if(S[i]=='c'){
            cout<<"No"<<"\n";
        }
    }
}