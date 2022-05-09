//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const Int INF=1010000000000000017LL;
const Int MOD=1000000007LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    Int N;cin>>N;
    vector<Int> t(N),l(N),r(N);
    REP(i,N)cin>>t[i]>>l[i]>>r[i];
    REP(i,N){t[i]--;l[i]--;r[i]--;}

    Double l1,l2,r1,r2;
    Int ans=0;
    REP(i,N-1){
        l1=l[i];r1=r[i];
        if(t[i]&2)l1+=0.5;
        if(t[i]&1)r1-=0.5;
        FOR(j,i+1,N){
            l2=l[j],r2=r[j];
            if(t[j]&2)l2+=0.5;
            if(t[j]&1)r2-=0.5;

            if( (l1<=r2&&l2<=r1)||
                (l2<=r1&&l1<=r2) ){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}