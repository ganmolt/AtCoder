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
    int n;cin>>n;
    vector<int> a(n),b(n),c(n),d(n);
    REP(i,n)cin>>a[i]>>b[i];
    REP(i,n)cin>>c[i]>>d[i];

    vector<pair<pair<int,int>,pair<int,int>>> v;
    REP(i,n){
        v.push_back({{a[i],0},{a[i],b[i]}});
    }
    REP(i,n){
        v.push_back({{c[i],1},{c[i],d[i]}});
    }
    sort(v.begin(),v.end(),greater<pair< pair<int,int>,pair<int,int> >>());

    vector<int> v2;
    int cnt=0;
    REP(i,2*n){
        //cout<<"v2: ";REP(i,v2.size())cout<<v2[i]<<" ";cout<<"\n";
        if(v[i].first.second==0){//zako
            //v2.push_back(v[i].second.second);
            //cout<<"srch: "<<v[i].second.second;//<<"\n";
            auto it=upper_bound(v2.begin(),v2.end(),v[i].second.second);
            if(it-v2.begin()<v2.size()){
                v2.erase(it);
                cnt++;
            }
            //cout<<", cnt: "<<cnt<<"\n";
        }
        if(v[i].first.second==1){
            //cout<<"add: "<<v[i].second.second<<"\n";
            v2.push_back(v[i].second.second);
            sort(v2.begin(),v2.end());
        }
        //cout<<v[i].second.first<<","<<v[i].second.second<<" "<<v[i].first.second<<"\n";
    }
    cout<<cnt<<"\n";
}
    