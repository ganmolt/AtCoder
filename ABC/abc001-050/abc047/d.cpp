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
    Int n,t;cin>>n>>t;
    vector<Int> a(n);REP(i,n)cin>>a[i];

    vector<pair<Int,int>> m(n);
    REP(i,n){
        if(i==0)m[i]={INF,0};
        else{
            if(a[i-1]<m[i-1].first){
                m[i]={a[i-1],1};
            }else if(a[i-1]==m[i-1].first){
                m[i].second++;
            }else{
                m[i]=m[i-1];
            }
        }
    }

    Int M=-1,cnt=0;
    REP(i,n){
        if(a[i]-m[i].first>M){
            M=a[i]-m[i].first;
            cnt=m[i].second;
        }else if(a[i]-m[i].first==M){
            cnt+=m[i].second;
        }else{
            continue;
        }
    }
    cout<<cnt<<"\n";
}