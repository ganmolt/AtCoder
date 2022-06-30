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
    /*if(n==k){
        cout<<1<<"\n";
        exit(0);
    }*/
    Int l,r;
    l=find(a.begin(),a.end(),1)-a.begin();r=n-l-1;
    //cout<<l<<" "<<r<<"\n";
    //if(l==1)l=0;
    //if(r==1)r=0;
    Int cnt=0;
    while(l>=1){
        l-=(k-1);cnt++;
    }
    while(r>=1){
        r-=(k-1);cnt++;
    }
    if(0-l-r>=k-1)cnt--;
    //cout<<(n+k-1)/k<<"\n";
    cout<<cnt<<"\n";
}