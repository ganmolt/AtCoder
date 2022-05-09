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
    string S;cin>>S;
    ll ans=0;ll z=0;ll cnt=0;
    ll N=S.size();
    ll n[N];n[0]=0;ll sI=-1;
    REPS(i,N-1){
        if(sI==-1&&S[i]=='<'){//増加
            n[i]=n[i-1]+1;
        }
        if(S[i-1]=='<'&&S[i]=='>'){//増加/減少
            sI=i;
            if(i==N-1)n[i]=0;
        }
        if(sI!=-1&&S[i]=='>'){//減少中かつさらに減少
            cnt++;
            if(i==N-1){
                FOR(j,sI,i){
                    n[j]=cnt-(j-sI);
                }
            }
        }
        if(sI!=-1&&S[i]=='<'){//減少/増加
            FOR(j,sI,i){
                n[j]=cnt-(j-sI);
                //if(j==i-1)cnt=0;
            }
            if(i==N-1)n[i]=n[i-1]+1;
        }
        if(S[i-1]=='>'&&S[i]=='<'){
            n[i]=1;
        }
    }
    ll sm=0;
    REP(i,S.size()){
        cout<<n[i]<<" ";
    }
}