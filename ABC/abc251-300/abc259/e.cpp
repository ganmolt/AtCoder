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
    map<Int,Int> mp[n];
    REP(i,n){
        int m;cin>>m;
        map<Int,Int> tmp;
        REP(i,m){
            Int p,e;cin>>p>>e;
            tmp[p]=e;
        }
        mp[i]=tmp;
    }

    map<Int,Int> la[n],ra[n];
    la[0]=mp[0];FOR(i,1,n){
        la[i]=mp[i-1];
        for(auto r:mp[i]){
            chmax(la[i][r.first],mp[i][r.first]);
        }
    }
    ra[n-1]=mp[n-1];for(int i=n-2;i>=0;i--){
        ra[i]=ra[i+1];
        for(auto r:mp[i]){
            chmax(ra[i][r.first],mp[i][r.first]);
        }
    }
    Int ans=0;
    set<map<Int,Int>> s;
    REP(i,n){
        map<Int,Int> m=la[(i-1+n)%n];
        for(auto r:ra[(i+1)%n]){
            chmax(m[r.first],ra[(i+1)%n][r.first]);
        }
        s.insert(m);

    }
    cout<<s.size()<<"\n";

}