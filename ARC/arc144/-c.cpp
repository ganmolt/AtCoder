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
    if(n/2<k){
        cout<<"-1\n";
        return 0;
    }
    int i=0,j=0;
    vector<bool> used(n,false);
    vector<int> v(n,-1);

    REP(i,k){
        if(v[i]==!-1)continue;
        if(used[(k+i)%n+1])continue;
        used[(k+i)%n+1]=true;
        v[i]=(k+i)%n+1;
    }
    REP(i,k){
        if(v[n-1-k-i]!=-1)continue;
        if(used[n-i])continue;
        used[n-i]=true;
        v[n-1-k-i]=n-i;
    }
    while(true){
        break;
    }
    REP(i,n)cout<<i+1<<": "<<(used[i+1]==true?1:0)<<", ";cout<<"\n";
    REP(i,n)cout<<v[i]<<" ";cout<<"\n";
}
    