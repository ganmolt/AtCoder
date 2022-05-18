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
    string s;cin>>s;
    int q;cin>>q;
    vector<int> t(q),a(q),b(q);
    REP(i,q){
        cin>>t[i]>>a[i]>>b[i];
        a[i]--;b[i]--;
    }

    bool flip=false;

    int idx[2*n];iota(idx,idx+sizeof(idx)/sizeof(idx[0]),0);
    //REP(i,2*n)cout<<idx[i]<<" ";cout<<"\n";
    REP(i,q){
        if(t[i]==1){
            int i1=a[i],i2=b[i];
            if(flip){
                if(i1<n)i1+=n;
                else i1-=n;
                if(i2<n)i2+=n;
                else i2-=n;
            }
            swap(idx[i1],idx[i2]);
        }
        if(t[i]==2){
            flip=1-flip;
        }
    }
    if(flip){
        FOR(i,n,2*n)cout<<s[idx[i]];
        REP(i,n)cout<<s[idx[i]];
    }else{
        REP(i,2*n)cout<<s[idx[i]];
    }
    cout<<"\n";
}