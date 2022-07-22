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
    Int n,k;cin>>n>>k;
    vector<Int> a(n);REP(i,n)cin>>a[i];
    vector<Int> b(n);REP(i,n)cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    Int lb = 0;
    Int ub = 4e18;

    vector<pair<Int,Int>> v;

    while(lb < ub-1){
        Int m = (ub+lb)/2;
        Int ans=0;
        Int max_val = 0;

        REP(i,n){
            auto srch = upper_bound(b.begin(),b.end(),m/a[i]);

            if(srch == b.begin()){
                continue;
            }

            Int cnt = srch - b.begin();
            ans += cnt;
            srch--;
            chmax(max_val, (*srch) * a[i]);
        }
        v.push_back({m, max_val});
        if(ans == k){
            cout<<max_val<<"\n";
            return 0;
        }
        else if(k < ans){
            ub = m;
        }
        else{
            lb = m;
        }
    }

    sort(v.begin(),v.end());
    cout<< upper_bound(v.begin(),v.end(), make_pair(lb,INF) )->second <<"\n";
}