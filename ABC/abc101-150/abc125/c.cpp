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
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
//-----------------------------------------
int main(void){
    int n;cin>>n;
    vector<int> a(n);REP(i,n)cin>>a[i];

    vector<int> la(n),ra(n);
    la[0]=a[0];FOR(i,1,n)la[i]=gcd(la[i-1],a[i]);
    ra[n-1]=a[n-1];for(int i=n-2;i>=0;i--)ra[i]=gcd(ra[i+1],a[i]);
    int ans=0;
    REP(i,n){
        if(1<=i){
            if(i<=n-2)chmax(ans,gcd(la[i-1],ra[i+1]));
            else chmax(ans,la[i-1]);
        }else{
            chmax(ans,ra[i+1]);
        }
    }
    cout<<ans<<"\n";
}