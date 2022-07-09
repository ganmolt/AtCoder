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
    vector<Int> s(n),t(n);
    REP(i,n)cin>>s[i];REP(i,n)cin>>t[i];

    vector<vector<int>> rows;
    bool done[n];REP(i,n)done[i]=false;
    REP(i,n){//ans
        vector<int> tmp;
        if(done[t[i]])continue;
        FOR(j,find(s.begin(),s.end(),t[i]),n){
            if(done[j])continue;
            tmp.push_back(t[i]);
            done[j]=true;
        }
        rows.push_back(tmp);
    }
    REP(i,rows.size()){
        REP(j,rows[i])cout<<rows[i][j]<<" ";
        cout<<"\n";
    }
}