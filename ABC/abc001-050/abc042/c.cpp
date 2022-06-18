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
int n,k;
int ans=1e9;
vector<int> c={0,1,2,3,4,5,6,7,8,9};
vector<int> cc;
void dfs(int i){
    if(i>=n)chmin(ans,i);
    //cout<<i<<" ";
    for(auto r:cc){
        if(i*10+r >= n){
            chmin(ans, i*10+r);
            return;
        }else{
            dfs(i*10+r);
        }
    }
}
int main(void){
    cin>>n>>k;
    vector<int> d(k);
    REP(i,k)cin>>d[i];
    set_difference(c.begin(), c.end(),
                    d.begin(), d.end(),
                    inserter(cc, cc.end()));
    //for(auto rr:cc)cout<<rr<<" ";cout<<"\n";
    vector<int> ccc=cc;
    if(ccc[0]==0)ccc.erase(ccc.begin());
    for(auto r:ccc)dfs(r);
    cout<<ans<<"\n";
}

