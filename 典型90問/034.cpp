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
    int n,k;cin>>n>>k;
    vector<int> a(n);REP(i,n)cin>>a[i];

    map<int,int> m;
    int cnt=0;int ans=0;
    for(int l=0,r=0;l<n&&r<n;){
        if(cnt>k){
            l++;
            m[a[l-1]]--;
            if(m[a[l-1]]==0)cnt--;
        }else{
            r++;
            //cout<<r-1<<","<<a[r-1]<<","<<m[a[r-1]]<<" : ";
            if(m[a[r-1]]==0)cnt++;
            m[a[r-1]]++;
        }
        //cout<<"l: "<<l<<", "<<"r: "<<r<<" "<<"k:"<<k<<" "<<cnt<<"\n";
        if(cnt<=k)chmax(ans,r-l);
    }
    cout<<ans<<"\n";
}