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
    Int x,a,d,n;cin>>x>>a>>d>>n;
    Int M,m;
    

    if(d>0){
        M=a+d*(n-1);
        m=a;
    }else{
        M=a;
        m=a+d*(n-1);
        a=m;d*=-1;
    }
    Int ans;
    if(m<=x && x<=M){
        ans=min((x-a)%d, d-(x-a)%d);
        if(d==0){
            ans=x-a;
        }
    }else if(x<m){
        ans=m-x;
    }else{
        ans=x-M;
    }

    
    
    cout<<ans<<"\n";
}
    
    