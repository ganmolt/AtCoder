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
const Int mod=998244353;
int main(void){
    int n;cin>>n;
    Int l;cin>>l;
    string s[n];REP(i,n)cin>>s[i];

    Int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        string list="abcdefghijklmnopqrstuvwxyz";
        int bitcnt=0;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                string tmp;
                set_intersection(list.begin(),list.end(),
                                s[i].begin(),s[i].end(),
                                back_inserter(tmp)
                );
                list=tmp;
                bitcnt++;
                //cout<<"1";
            }else{
                //cout<<"0";
            }
        }
        
        if(bitcnt==0)continue;
        Int tmp=1;
        tmp=pow(list.size(),l,mod);
        
        if(bitcnt%2==1)ans=(ans+tmp)%mod;
        else ans=(ans+mod-tmp)%mod;

        //cout<<", "<<list<<", "<<tmp<<"\n";
    }
    cout<<ans<<"\n";
}