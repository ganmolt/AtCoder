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
    vector<int> l(n),r(n);REP(i,n)cin>>l[i]>>r[i];

    int a[220000];REP(i,220000)a[i]=0;
    REP(i,n){
        a[l[i]]++;
        a[r[i]]--;
    }
    FOR(i,1,220000){
        a[i]+=a[i-1];
    }
    vector<pair<int,int>> v;
    int m,M;bool b=false;
    REP(i,220000){
        if(b==false&&a[i]!=0){
            m=i;
            b=true;
        }

        if(b==true&&a[i]==0){
            M=i;
            v.push_back({m,M});
            b=false;
        }
    }
    for(auto r:v){
        cout<<r.first<<" "<<r.second<<"\n";
    }
}