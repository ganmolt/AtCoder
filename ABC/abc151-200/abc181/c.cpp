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
    vector<int> x(n),y(n);REP(i,n)cin>>x[i]>>y[i];
    REP(i,n-2){
        FOR(j,i+1,n-1){
            FOR(k,j+1,n){
                if(x[j]-x[i]==0&&x[k]-x[j]==0)YES;
                Double a1=(y[j]-y[i])*1.0/(x[j]-x[i]);
                Double a2=(y[k]-y[j])*1.0/(x[k]-x[j]);
                //cout<<a1<<","<<a2<<"\n";
                if(a1==a2)YES;
            }
        }
    }
    NO;
}