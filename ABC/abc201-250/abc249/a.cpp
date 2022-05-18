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
    int a,b,c,d,e,f,x;cin>>a>>b>>c>>d>>e>>f>>x;
    int ac=a+c,df=d+f;
    int am=x%ac,dm=x%df;
    int y1,y2;
    y1=(x/ac)*a*b;
    y2=(x/df)*d*e;
    y1+=min(a,am)*b;
    y2+=min(d,dm)*e;
    if(y1<y2){
        cout<<"Aoki";
    }else if(y1>y2){
        cout<<"Takahashi";
    }else{
        cout<<"Draw";
    }cout<<"\n";
}