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
    int n,qn;cin>>n>>qn;
    vector<int> v(n),q(qn);REP(i,qn)cin>>q[i],q[i]--;REP(i,n)v[i]=i;

    vector<int> idx(n);REP(i,n)idx[i]=i;
    REP(i,qn){
        if(idx[q[i]]!=n-1){
            int tmp=v[idx[q[i]]];
            int to=v[idx[q[i]]+1];
            v[idx[q[i]]]=to;
            v[idx[q[i]]+1]=tmp;

            idx[tmp]++;
            idx[to]--;
        }else{
            int tmp=v[idx[q[i]]];
            int to=v[idx[q[i]]-1];
            v[idx[q[i]]]=to;
            v[idx[q[i]]-1]=tmp;

            idx[tmp]--;
            idx[to]++;
        }
    }
    vector<int> ans(n);
    REP(i,n){
        ans[idx[i]]=i+1;
    }
    REP(i,n){
        cout<<ans[i]<<(i==n-1?"\n":" ");
    }

}