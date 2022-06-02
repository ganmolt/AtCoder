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
    int n,q;cin>>n>>q;
    vector<int> a(n);REP(i,n)cin>>a[i];
    vector<int> t(q),x(q),y(q);REP(i,q)cin>>t[i]>>x[i]>>y[i],x[i]--,y[i]--;

    int shift=0;
    REP(i,q){
        if(t[i]==1){
            int X=(x[i]-shift+n)%n;
            int Y=(y[i]-shift+n)%n;
            a[X]^=a[Y]^=a[X]^=a[Y];
        }else if(t[i]==2){
            shift++;shift%=n;
        }else{
            cout<<a[(x[i]-shift+n)%n]<<"\n";
        }
    }
}