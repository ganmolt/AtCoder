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
    int n,m;cin>>n>>m;
    vector<int> a(m);REP(i,m)cin>>a[i];

    if(m==0)cout<<1<<"\n",exit(0);

    sort(a.begin(),a.end());
    vector<int> v;
    for(int i=0;i<=m;i++){
        int t;
        if(i==0)t=a[i]-1;
        else if(i==m)t=n-a[i-1];
        else t=a[i]-a[i-1]-1;
        if(t!=0)v.push_back(t);
    }
    
    int mn=1000000007;
    for(auto r:v){
        chmin(mn,r);
    }
    int ans=0;
    for(auto r:v){
        ans+=(r+mn-1)/mn;
    }
    cout<<ans<<"\n";
}