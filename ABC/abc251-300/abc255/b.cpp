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
Double D(Int x1,Int y1, Int x2, Int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(void){
    int n,k;cin>>n>>k;
    vector<Int> a(k);REP(i,k)cin>>a[i],a[i]--;
    vector<Int> x(n),y(n);REP(i,n)cin>>x[i]>>y[i];
    vector<Double> v(n,1e9);
    REP(i,n){
        //cout<<i<<": ";
        REP(j,k){
            //if(i==a[j]){v[i]=0; continue; }
            //cout<<D(x[i], y[i], x[a[j]], y[a[j]])<<" ";
            chmin(v[i], D(x[i], y[i], x[a[j]], y[a[j]]));
        }//cout<<"\n";
    }
    Double ans=0;
    REP(i,n){
        //cout<<v[i]<<"\n";
        chmax(ans, v[i]);
    }
    cout<<dcml(10)<<ans<<"\n";
}