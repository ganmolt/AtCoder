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
    int n;cin>>n;
    vector<Int> x(n),y(n);REP(i,n)cin>>x[i]>>y[i];
    vector<pair<Double,pair<Int,Int>>> v;
    REP(i,n){
        //Double dd=x[i]*x[i]+y[i]*y[i];
        Double dg=atan2(y[i],x[i])*180/PI;
        v.push_back({dg,{x[i],y[i]}});
    }
    sort(v.begin(),v.end());
    //REP(i,n)cout<<"(x,y)=("<<v[i].second.first<<","<<v[i].second.second<<"), "<<v[i].first<<"\n";
    Double ans=0;
    REP(i,n){
        Int nx=0,ny=0;
        //Double tmp=0;
        //cout<<i<<": ";
        REP(j,n){
            //cout<<nx<<","<<ny<<"\n";
            //cout<<sqrt(nx*nx+ny*ny)<<" ";
            int idx=(i+j)%n;
            nx+=v[idx].second.first,ny+=v[idx].second.second;
            chmax<Double>(ans,sqrt(nx*nx+ny*ny));
        }//cout<<"\n";

    }
    cout<<dcml(10)<<ans<<"\n";
}