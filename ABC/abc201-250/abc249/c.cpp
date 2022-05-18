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
    int n,k;cin>>n>>k;
    vector<string> s(n);REP(i,n)cin>>s[i];
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        map<char,int> m;
        int cnt=0;
        for(int i=0;i<n;i++){
            if((1<<i)&bit){
                //cout<<1<<" ";
                REP(j,s[i].size()){
                    m[s[i][j]]++;
                }
            }else{
                //cout<<0<<" ";
            }
        }
        for(auto r:m){
            if(r.second==k)cnt++;
        }
        chmax(ans,cnt);
    }
    cout<<ans<<"\n";
}