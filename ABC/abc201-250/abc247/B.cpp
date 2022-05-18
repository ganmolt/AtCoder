//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    Int N;cin>>N;
    vector<pair<string,string>> v(N);
    REP(i,N)cin>>v[i].first>>v[i].second;
    REP(i,N){
        bool flag_f=true,flag_s=true;
        REP(j,N){
            if(i==j)continue;
            if(v[i].first==v[j].first || v[i].first==v[j].second){
                flag_f=false;
            }
            if(v[i].second==v[j].first || v[i].second==v[j].second){
                flag_s=false;
            }
        }
        if(!flag_f&&!flag_s){
            cout<<"No\n";
            exit(0);
        }
    }
    cout<<"Yes\n";
}