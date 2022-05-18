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
int g1(int n){
    string s=to_string(n);
    vector<int> v;
    REP(i,s.size())v.push_back(s[i]-'0');
    sort(v.begin(),v.end(),greater<int>());
    int ret=0;
    REP(i,v.size())ret=ret*10+v[i];
    return ret;
}
int g2(int n){
    string s=to_string(n);
    vector<int> v;
    REP(i,s.size())v.push_back(s[i]-'0');
    sort(v.begin(),v.end());
    int ret=0;
    REP(i,v.size())ret=ret*10+v[i];
    return ret;
}
int main(void){
    Int n,k;cin>>n>>k;
    Int now=n;
    REP(i,k){
        now=g1(now)-g2(now);
    }
    cout<<now<<"\n";
}