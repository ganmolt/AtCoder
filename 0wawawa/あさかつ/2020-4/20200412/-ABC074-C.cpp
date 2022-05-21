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
ld mxP,mxV,mxS;
void cmx(ld p,ll v,ll s){
    if(mxP<=p){
        mxP=p;mxV=v;mxS=s;
    }
}
int main(void){
    ll A,B,C,D,E,F;cin>>A>>B>>C>>D>>E>>F;
    ld PMAX=E/(100.0+E);
    //cout<<"PMAX:"<<PMAX<<"\n";
    REP(i1,30/A+1){
        ll V1=A*100*i1;
        if(V1>F)break;
        REP(i2,30/B+1){
            ll V2=V1+B*100*i2;
            if(V2==0)continue;
            if(V2>F)break;
            REP(j1,(F/C)+1){
                ll S1=C*j1;
                if(S1+V2>F)break;
                REP(j2,(F/D)+1){
                    ll S2=S1+D*j2;
                    ll V=S2+V2;
                    if(V>F)break;
                    ld P=S2*1.0/V;
                    if(P>PMAX)break;
                    //cout<<V<<" "<<S2<<" "<<" "<<P<<"<"<<PMAX<<"\n";
                    if(P<=mxP)continue;
                    
                    //cout<<P<<" "<<V<<" "<<S2<<"\n";
                    cmx(P,V,S2);//cout<<":::"<<mxV<<" "<<mxS<<"\n";
                }
            }
        }
    }
    cout<<mxV<<" "<<mxS<<"\n";
}