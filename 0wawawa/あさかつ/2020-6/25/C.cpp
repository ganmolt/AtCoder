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
//ディ　ブルデ　The　尊厳
//-----------------------------------------
int main(void){
    string S;cin>>S;
    ll Q;cin>>Q;
    ll rev=0;
    string s[2];
    while(Q --> 0){
        //cout<<"nokori:"<<Q<<"\n";
        ll q;cin>>q;
        if(q==1){
            //cout<<1<<":";
            rev++;
        }
        else if(q==2){
            //cout<<2<<":";
            ll f;char c;cin>>f>>c;
            s[(f-1+rev)%2].push_back(c);
        }
    }
    
    reverse(ALLv(s[0]));
    if(rev%2==0){
        cout<<s[0]<<S<<s[1]<<"\n";
    }
    else{
        reverse(ALLv(s[0]));
        reverse(ALLv(S));
        reverse(ALLv(s[1]));
        cout<<s[1]<<S<<s[0]<<"\n";
    }
    
}
