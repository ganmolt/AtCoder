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
    string c;
    map<string,pair<string,string>> m;
    m["襷"]={"00","0"},m["薔"]={"01","111"},m["鑑"]={"10","10"},m["鬱"]={"11","110"};
    vector<string> cs;
    while(cin>>c){
        cs.push_back(c);
    }
    int l=0;
    REP(i,cs.size()){
        l+=m[cs[i]].first.size();
        cout<<m[cs[i]].first<<" ";
    }cout<<"平均符号語長"<<l*1.0/cs.size()<<" "<<"\n";
    l=0;
    REP(i,cs.size()){
        l+=m[cs[i]].second.size();
        cout<<m[cs[i]].second<<" ";
    }cout<<"平均符号語長"<<l*1.0/cs.size()<<" "<<"\n";
}
//鬱 鑑 鑑 襷 薔 薔 襷 鬱 鬱 薔 襷 鑑 襷 鬱 薔 鑑
