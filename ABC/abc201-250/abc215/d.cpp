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
vector<pair<Int,Int>> prime_factor(Int n){
    vector<pair<Int,Int>> ret;
    for(Int i=2;i*i<=n;i++){
        if(n%i!=0)continue;
        Int tmp=0;
        while(n%i==0){
            tmp++;
            n/=2;
        }
        ret.push_back(make_pair(i,tmp));
    }
    if(n!=1)ret.push_back(make_pair(n,1));
    return ret;
}
int main(void){
    Int n,m;cin>>n>>m;
    vector<Int> a(n);
    Int MAX=m;
    REP(i,n){
        cin>>a[i];chmax(MAX,a[i]);
    }

    bool isCoPrime[110000];
    bool isAi[110000];
    REP(i,110000)isCoPrime[i]=true;isCoPrime[0]=false;
    REP(i,110000)isAi[i]=false;
    REP(i,n){
        vector<pair<Int,Int>> primes=prime_factor(a[i]);
        for(auto p:primes)isAi[p.first]=true;
    }

    for(int i=1;i<=MAX;i++){
        if(isAi[i]&&isCoPrime[i]){
            for(int j=1;i*j<=MAX;j++){
                isCoPrime[i*j]=false;
            }
        }
    }
    vector<Int> ans;
    for(int i=1;i<=MAX;i++){
        if(isCoPrime[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    REP(i,ans.size())cout<<ans[i]<<"\n";
}