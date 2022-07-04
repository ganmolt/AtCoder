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
    vector<int> a(n);
    REP(i,n){
        Int aa;cin>>aa;
        a[i]=aa%200;
    }
    //REP(i,n)cout<<a[i]<<" ";cout<<"\n";

    queue<tuple<int,int,vector<int>>> que;//val, lastIdx
    vector<vector<int>> v[200];
    
    v[a[0]].push_back({0});
    que.push({a[0],0,{0}});
    que.push({0,0,{}});
    while(!que.empty()){
        auto [val,lidx,idxs]=que.front();que.pop();
        if(v[val].size()>=2)break;

        int nidx=lidx+1;
        if(nidx==n)break;
        //lidx+1を使わない
        que.push({val,nidx,idxs});

        //lidx+1を使う
        int nxtVal=(val+a[nidx])%200;
        idxs.push_back(nidx);
        
        v[nxtVal].push_back(idxs);
        que.push({nxtVal,nidx,idxs});
    }
    REP(i,200){
        if(v[i].size()==2){
            cout<<"Yes\n";
            for(auto r:v[i]){
                cout<<r.size()<<" ";
                REP(j,r.size()){
                    cout<<r[j]+1<<(j==r.size()-1?"\n":" ");
                }
            }
            exit(0);
        }
    }
    NO;
}