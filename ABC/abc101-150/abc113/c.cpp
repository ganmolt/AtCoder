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
    int n,m;cin>>n>>m;
    vector<int> p(m),y(m);REP(i,m)cin>>p[i]>>y[i],p[i]--;

    vector<pair<int,int>> v[n];
    REP(i,m){
        v[p[i]].push_back({y[i],i});
    }
    REP(i,n){
        sort(v[i].begin(),v[i].end());
    }
    map<int,string> ans;
    REP(i,n){
        REP(j,v[i].size()){
            string str;
            string si=to_string(i+1);
            REP(i,6-si.size())str+='0';
            str+=si;
            string sj=to_string(j+1);
            REP(j,6-sj.size())str+='0';
            str+=sj;
            ans[v[i][j].second]=str;
        }
    }
    REP(i,ans.size()){
        cout<<ans[i]<<"\n";
    }
}