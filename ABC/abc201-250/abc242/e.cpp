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
const Int mod=998244353LL;
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
Int pow(Int x, Int n, Int mod=1e9+7){
    Int ret=1;
    while(n>0){
        if(n&1)ret=ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}
//-----------------------------------------
int main(void){
    int t;cin>>t;
    vector<Int> n(t);vector<string> s(t);
    REP(i,t)cin>>n[i]>>s[i];

    REP(i,t){
        Int ans=0;
        REP(j,(n[i]+1)/2){
            ans=ans+(s[i][j]-'A')*pow(26,( (n[i]+1)/2-j-1 ),mod);
            ans%=mod;
        }
        string s2=s[i].substr(0,n[i]/2+(n[i]%2==1));
        //cout<<s2<<",";
        string rs=s[i];reverse(rs.begin(),rs.end());//cout<<rs<<"\n";
        s2+=rs.substr(n[i]/2+(n[i]%2==1));
        //cout<<s[i]<<"\n";
        //cout<<s2<<"\n";
        ans+=(s2<=s[i]);
        ans%=mod;
        cout<<ans<<"\n";
    }
    
}