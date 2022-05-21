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
int main(void){
    ll N;cin>>N;
    vi A(N);vi B(N);
    REP(i,N){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
    }
    vi C=A;C.insert(C.end(),ALLv(B));
    ll n=C.size();
    ll ANS=INF;
    REP(i,n){
        ll s=C[i];
        REP(j,n){
            ll g=C[j];
            if(s>g)continue;
            ll d=g-s;
            //すべての客について
            ll Ans=0;//sum
            //cout<<s<<" "<<g<<":";
            REP(k,N){
                //自明A[k]<B[k]
                ll ans=d;
                if(B[k]<s){
                    ans+=(s-A[k])*2;
                }else if(A[k]>g){
                    ans+=(B[k]-g)*2;
                }else{
                    ll d1=0,d2=0;
                    if(A[k]<s)d1=s-A[k];
                    if(g<B[k])d2=B[k]-g;
                    ans+=d1*2+d2*2;
                    //cout<<"("<<d1<<"x2+"<<d2<<"x2)";
                }
                //cout<<ans<<(k!=N-1?"+":"");
                Ans+=ans;
            }
            //cout<<"="<<Ans<<"\n";
            ANS=min(ANS,Ans);
        }
    }
    cout<<ANS<<"\n";
}