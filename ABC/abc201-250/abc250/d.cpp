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
    Int n;cin>>n;
    bool isPrime[1000001];
    REP(i,1000001)isPrime[i]=true;
    for(int i=2;i<=1000000;i++){
        if(isPrime[i]){
            for(int k=2;i*k<=1000000;k++)isPrime[i*k]=false;
        }
    }
    vector<Int> prime;
    for(int i=2;i<=1000000;i++)if(isPrime[i])prime.push_back(i);
    //for(auto r:prime)r<=n&&cout<<r<<"\n";
    vector<Int> pow3s;
    Int cnt=0;
    for(auto r:prime)pow3s.push_back(r*r*r);
    sort(pow3s.begin(),pow3s.end());
    for(int i=0;i<prime.size();i++){
        auto it=lower_bound(pow3s.begin(),pow3s.end(),(n+prime[i])/prime[i]);it-=1;
        int d=it-pow3s.begin()-i;
        if(d>=1){
            //cout<<*it<<","<<d<<" ";
            cnt+=d;
        }
    }
    cout<<cnt<<"\n";
}
    
