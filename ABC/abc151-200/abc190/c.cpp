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
    vector<int> a(m),b(m);
    REP(i,m)cin>>a[i]>>b[i];
    REP(i,m)a[i]--,b[i]--;
    int k;cin>>k;
    vector<int> c(k),d(k);
    REP(i,k)cin>>c[i]>>d[i];
    REP(i,k)c[i]--,d[i]--;

    Int ans=0;
    for(int bit=0;bit<(1<<k);bit++){

        vector<int> cnt(n);
        for(int i=0;i<k;i++){
            if((1<<i)&bit){
                cnt[c[i]]++;
            }
            else{
                cnt[d[i]]++;
            }
        }//cout<<"\n";
        Int tmp=0;
        REP(j,m){
            //cout<<a[j]<<":"<<cnt[a[j]]<<", "<<b[j]<<":"<<cnt[b[j]];
            if(cnt[a[j]]>0&&cnt[b[j]]>0)tmp++;
            //cout<<"\n";
        }
        //cout<<"{";REP(i,n)cout<<i<<":"<<cnt[i]<<" ";cout<<"}\n";
        //cout<<tmp<<"\n";

        chmax(ans,tmp);
    }
    cout<<ans<<"\n";
}