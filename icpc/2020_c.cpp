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
vector<Int> primeFactor(Int n){
    vector<Int> ret={1};
    Int sn=sqrt(n);
    for(Int i=2;i<=sn;i++){
        while(n%i==0){
            n/=i;
            ret.push_back(i);
        }
    }
    if(n!=1)ret.push_back(n);
    return ret;
}

//-----------------------------------------
vector<Int> primes;
Int p;
Int ans=INF;
void dfs(int i, Int p1, Int p2, Int p3){
    if(i==primes.size()){chmin(ans,p1+p2+p3);return;}
    if(ans<=p1+p2+p3)return;
    
    dfs(i+1,p1*primes[i],p2,p3);
    dfs(i+1,p1,p2*primes[i],p3);
    dfs(i+1,p1,p2,p3*primes[i]);
}
int main(void){
    while(true){
        cin>>p;
        if(p==0)break;
        primes=primeFactor(p);
        sort(primes.begin(),primes.end(),greater<Int>());
        cout<<primes.size()<<"\n";
        REP(i,primes.size())cout<<primes[i]<<" ";cout<<"\n";
        ans=p+2;
        dfs(0,1,1,1);
        cout<<ans<<"\n";
    }
}
