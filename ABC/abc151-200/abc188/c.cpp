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
    int N=1;while(n-->0)N*=2;
    vector<pair<int,int>>a(2*N);REP(i,N)cin>>a[i].first,a[i].second=i;
    if(n==1)if(a[0]<a[1]){
        cout<<0<<"\n";
    }else{
        cout<<1<<"\n";
    }

    int k=N;
    for(int i=0,kc=0;i<N;i++,kc++){
        if(kc>k)k/=2,kc=0;
        a[i+k]=max(a[i*2],a[i*2+1]);
    }
    //REP(i,2*N)cout<<a[i].second+1<<" ";cout<<"\n";
    cout<<min(a[2*N-3],a[2*N-4]).second+1<<"\n";
}