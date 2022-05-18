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
    vector<string> s(n);
    vector<int> p(n);
    REP(i,n)cin>>s[i]>>p[i];
    struct Rstrnt{
        string s;int p;int idx;
        bool operator<(const Rstrnt r){
            if(s==r.s)return p>r.p;
            return s<r.s;
        }
    };
    vector<Rstrnt> v(n);
    REP(i,n){
        v[i].s=s[i];
        v[i].p=p[i];
        v[i].idx=i+1;
    }
    sort(v.begin(),v.end());
    for(auto r:v){
        cout<<r.idx<<"\n";
    }
}