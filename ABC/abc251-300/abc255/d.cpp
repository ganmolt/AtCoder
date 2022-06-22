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
    int n,q;cin>>n>>q;
    vector<Int> a(n),A(n),x(q);
    REP(i,n)cin>>a[i];
    REP(i,q)cin>>x[i];
    sort(a.begin(),a.end());
    REP(i,n){
        A[i]=a[i];if(i==0)continue;
        A[i]+=A[i-1];
    }
    REP(i,q){
        Int ans=0;

        Int c1=lower_bound(a.begin(),a.end(),x[i])-a.begin();
        Int tmp1;
        if(c1==0)tmp1=-1;
        else tmp1=x[i]*c1 -A[c1-1];

        if(tmp1!=-1)ans+=tmp1;
        //cout<<c1<<","<<tmp1;

        Int c2=upper_bound(a.begin(),a.end(),x[i])-a.begin();
        Int tmp2;
        if(c2==n)tmp2=-1;
        else tmp2=A[n-1]-(c2==0?0:A[c2-1]) - x[i]*(n-c2);
        if(tmp2!=-1)ans+=tmp2;
        //cout<<"A[n-1]: "<<A[n-1]<<" A[c2-1]: "<<A[c2-1]<<" ";
        //cout<<c2<<","<<tmp2;

        cout<<ans<<"\n";
    }
}