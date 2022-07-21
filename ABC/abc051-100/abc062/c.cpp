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
    Int h,w;cin>>h>>w;
    
    Int s1,s2,s3;
    Int ans=INF;
    for(int i=1;i<=h/2;i++){
        s1 = i*w;
        int h_=h-i;
        
        s2 = h_/2 * w;
        s3 = (h_-(h_/2)) * w;

        if(s1<0 || s2<0 || s3<0)continue;

        chmin(ans, max({s1,s2,s3})-min({s1,s2,s3}) );

        s2 = w/2 * h_;
        s3 = (w-(w/2)) * h_;

        if(s1<0 || s2<0 || s3<0)continue;

        chmin(ans, max({s1,s2,s3})-min({s1,s2,s3}) );
    }

    for(int i=1;i<=w/2;i++){
        s1 = i*h;
        int w_=w-i;
        
        s2 = w_/2 * h;
        s3 = (w_-(w_/2)) * h;

        if(s1<0 || s2<0 || s3<0)continue;

        chmin(ans, max({s1,s2,s3})-min({s1,s2,s3}) );

        s2 = h/2 * w_;
        s3 = (h-(h/2)) * w_;

        if(s1<0 || s2<0 || s3<0)continue;

        chmin(ans, max({s1,s2,s3})-min({s1,s2,s3}) );
    }

    cout<<ans<<"\n";
}