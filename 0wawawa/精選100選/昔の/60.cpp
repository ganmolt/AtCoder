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
    ll VSize,ESize;cin>>VSize>>ESize;
    ll d[VSize][VSize];
    memset(d,0x1f,sizeof(d));REP(i,VSize)d[i][i]=0;
    REP(i,ESize){
        ll s,t,d0;cin>>s>>t>>d0;
        d[s][t]=d0;
    }
    
    REP(k,VSize){
        REP(i,VSize){
            REP(j,VSize){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    REP(i,VSize)if(d[i][i]<0){
        cout<<"NEGATIVE CYCLE\n";
        return 0;
    }
    REP(i,VSize){
        REP(j,VSize){
            cout<<(d[i][j]>=0x1f1f1f1f1f1f1f1?"INF":to_string(d[i][j]))<<(j==VSize-1?"\n":" ");
        }
    }
}