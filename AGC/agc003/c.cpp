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
    vector<Int> a(n);REP(i,n)cin>>a[i];

    vector<Int> v0,v1;
    REP(i,n){
        if(i%2==0)v0.push_back(a[i]);
    }
    sort(a.begin(),a.end());

    REP(i,n){
        if(i%2==1)v1.push_back(a[i]);
    }
    sort(v0.begin(),v0.end());
    sort(v1.begin(),v1.end());

    vector<Int> v2;
    set_intersection(v0.begin(),v0.end(),
                    v1.begin(),v1.end(),
                    inserter(v2, v2.end())
                    );
    cout<<v2.size()<<"\n";
}