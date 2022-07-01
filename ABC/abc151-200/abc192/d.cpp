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
    string s;Int m;cin>>s>>m;
    Int n=s.size();
    if(n==1){
        if(stoi(s)<=m)cout<<"1\n";
        else cout<<"0\n";
        exit(0);
    }

    int k0=0;
    REP(i,n){
        chmax(k0,s[i]-'0');
    }k0++;
    //cout<<"k0: "<<k0<<"\n";

    Int ans=0;
    Int lb=k0,ub=2e18;//ok,ng
    Int k=(lb+ub)/2;
    bool first=true;
    while(ub-lb>1){
        if(first)k=lb;
        else k=(lb+ub)/2;
        //cout<<"(lb,ub)=("<<lb<<","<<ub<<"), ";
        //cout<<"k: "<<k<<" => ";
        Int res=0;
        for(int i=0;i<n;i++){
            if(res>(Int(1e18)+k-1)/k){
                res=Int(1e18);res++;
                break;
            }
            res*=k;
            int d=s[i]-'0';
            res+=d;
            
            
        }
        //cout<<res<<",";
        
        if(res<=m)lb=k;
        else{
            if(first){
                cout<<"0\n";
                exit(0);
            }
            ub=k;
        }
        if(first)first=false;
        //cout<<"\n";
    }//cout<<"\n";
    cout<<lb-k0+1<<"\n";
}