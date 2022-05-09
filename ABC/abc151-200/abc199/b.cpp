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
    vector<int> a(n),b(n);
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    REP(i,n){a[i]--;b[i]--;}

    int A[1001];REP(i,1001)A[i]=0;
    REP(i,n){
        A[a[i]]++;
        A[b[i]+1]--;
    }
    FOR(i,1,1001)A[i]+=A[i-1];
    //REP(i,1001)cout<<A[i]<<"\n";
    int ans=0;
    REP(i,1001){
        if(A[i]==n)ans++;
    }
    cout<<ans<<"\n";
}