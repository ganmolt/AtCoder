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
    for(ll Q;cin>>Q && Q!=0;){
        ll t[24*3600+60*60+60];
        REP(i,24*3600+60*60+60)t[i]=0;
        REP(q,Q){
            string s1,s2;cin>>s1>>s2;
            while(s1.find(":")!=string::npos)s1.erase(s1.find(":"));
            ll h=(s1[0]-'0')*10+(s1[1]-'0');
            ll m=(s1[2]-'0')*10+(s1[3]-'0');
            ll s=(s1[4]-'0')*10+(s1[5]-'0');
            t[h*3600+m*60+s]++;
            while(s2.find(":")!=string::npos)s2.erase(s2.find(":"));
            h=(s2[0]-'0')*10+(s2[1]-'0');
            m=(s2[2]-'0')*10+(s2[3]-'0');
            s=(s2[4]-'0')*10+(s2[5]-'0');
            t[h*3600+m*60+s]++;
        }
        ll M=0;
        REPS(i,24*3600+60*60+60-1)t[i]+=t[i-1];
        REP(i,24*3600+60*60+60)M=max(M,t[i]);
        cout<<M<<"\n";
    }
}