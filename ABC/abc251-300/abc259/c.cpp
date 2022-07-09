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
vector<pair<char,int>> RLE(string s){
    vector<pair<char,int>> ret;
    char c;
    int i=0;int cnt=0;
    while(i<s.size()){
        if(i==0){
            c=s[i];
            cnt=1;
            i++;continue;
        }
        if(c==s[i]){
            i++;
            cnt++;
        }else{
            ret.push_back({c,cnt});
            cnt=1;
            c=s[i];
            i++;
        }
    }
    ret.push_back({c,cnt});
    return ret;
}
int main(void){
    string s,t;cin>>s>>t;
    vector<pair<char,int>> rs=RLE(s),rt=RLE(t);
    if(rs.size()!=rt.size())NO;
    REP(i,rs.size()){
        if(rs[i].first!=rt[i].first)NO;
        if(rs[i].second>rt[i].second)NO;
        if(rs[i].second<rt[i].second && rs[i].second<2)NO;
    }
    /*REP(i,rs.size()){
        cout<<rs[i].first<<":"<<rs[i].second<<" ";
    }cout<<"\n";*/
    YES;
}
