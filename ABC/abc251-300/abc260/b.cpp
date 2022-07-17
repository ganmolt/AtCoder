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
    int n,x,y,z;cin>>n>>x>>y>>z;
    vector<int> a(n),b(n);REP(i,n)cin>>a[i];REP(i,n)cin>>b[i];
    bool isPassed[n];REP(i,n)isPassed[i]=false;

    vector<pair<int,int>> aa(n),bb(n),cc(n);
    REP(i,n){
        aa[i]={a[i],-i};
        bb[i]={b[i],-i};
        cc[i]={a[i]+b[i],-i};
    }

    sort(aa.begin(),aa.end(),greater<pair<int,int>>());
    sort(bb.begin(),bb.end(),greater<pair<int,int>>());
    sort(cc.begin(),cc.end(),greater<pair<int,int>>());
    
    int cnt=0;
    REP(i,n){
        if(cnt==x)break;
        if(isPassed[-aa[i].second])continue;
        isPassed[-aa[i].second]=true;
        cnt++;
    }
    cnt=0;
    REP(i,n){
        if(cnt==y)break;
        if(isPassed[-bb[i].second])continue;
        isPassed[-bb[i].second]=true;
        cnt++;
    }
    cnt=0;
    REP(i,n){
        if(cnt==z)break;
        if(isPassed[-cc[i].second])continue;
        isPassed[-cc[i].second]=true;
        cnt++;
    }
    REP(i,n){
        if(isPassed[i])cout<<i+1<<"\n";
    }
}