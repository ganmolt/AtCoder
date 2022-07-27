//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"UNRESTORABLE\n",exit(0)
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
    string s,t;cin>>s>>t;
    int n = s.size();
    int m = t.size();
    if(n < m)NO;
    vector<string> ans;
    REP(i,n){
        bool OK = true;
        if(i+m > n)OK = false;
        for(int j=0;i+j<n && j<m;j++){
            if(s[i+j]=='?' || s[i+j]==t[j])continue;
            OK = false;
        }
        if(OK){
            string tmp = s.substr(0,i);
            tmp += t;
            tmp += s.substr(i+m);
            ans.push_back(tmp);
        }
    }
    if(ans.size()==0) NO;

    sort(ans.begin(),ans.end());
    for(auto r:ans[0]){
        cout<<(r=='?'?'a':r);
    }
    cout<<"\n";
}