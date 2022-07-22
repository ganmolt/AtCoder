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
vector<int> primeFactor(Int n){
    vector<int> ret;
    int sn=sqrt(n);
    for(int i=2;i<=sn;i++){
        while(n%i==0){
            n/=i;
            ret.push_back(i);
        }
    }
    if(n!=1)ret.push_back(n);
    return ret;
}
//-----------------------------------------
int main(void){
    Int n;cin>>n;
    vector<int> primes;
    map<int,int> m;
    for(int i=1;i<=n;i++){
        vector<int> ps = primeFactor(i);
        for(auto r:ps){
            m[r]++;
        }
    }
    Int ans=1;
    for(auto r:m){
        ans = ans * (r.second+1) % MOD;
    }
    cout<<ans<<"\n";
    
}