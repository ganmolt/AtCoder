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
bool isPrime[110000];
//-----------------------------------------
int main(void){
    int n;cin>>n;

    REP(i,110000)isPrime[i]=true;
    isPrime[1]=false;
    for(int i=2;i<=100000;i++){
        if(isPrime[i]){
            for(int j=2;i*j<=100000;j++){
                isPrime[i*j]=false;
            }
        }
    }
    vector<int> ans;
    int cnt=0;
    for(int i=1;i<=55555;i++){
        if(isPrime[i]){
            if(i%5==1){
                ans.push_back(i);
                cnt++;
            }
        }
        if(cnt==n){
            break;
        }
    }
    REP(i,cnt){
        cout<<ans[i]<<(i==cnt-1?"\n":" ");
    }
}