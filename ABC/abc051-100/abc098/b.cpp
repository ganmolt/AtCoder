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
    int n;string s;cin>>n>>s;
    int ans=0;
    REP(i,n){
        string s1=s.substr(0,i);
        string s2=s.substr(i,n-i);
        //cout<<s1<<","<<s2<<"\n";
        map<char,int> m1,m2;
        REP(j,s1.size())m1[s1[j]]++;
        REP(j,s2.size())m2[s2[j]]++;

        vector<char> v1,v2;
        transform(m1.begin(),m1.end(),back_inserter(v1),
                [](const auto &pair){
                    return pair.first;
                });
        
        transform(m2.begin(),m2.end(),back_inserter(v2),
                [](const auto &pair){
                    return pair.first;
                });

        vector<char> inter;
        set_intersection(v1.begin(),v1.end(),
                        v2.begin(),v2.end(),
                        inserter(inter,inter.end())
        );
        chmax<int>(ans,inter.size());
    }
    cout<<ans<<"\n";
}