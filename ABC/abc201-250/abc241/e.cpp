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
    Int n,k;cin>>n>>k;
    vector<Int> a(n);REP(i,n)cin>>a[i];

    Int loop=n;Int used[n];REP(i,n)used[i]=-1;
    Int cnt=0;
    REP(i,n){
        //exit(0);
        //cout<<i<<" ";
        cnt+=a[cnt%n];
        if(used[cnt%n]!=-1){
            loop=i-used[cnt%n];
        }
        used[cnt%n]=i;
        k--;
        if(k==0){
            cout<<cnt<<"\n";
            exit(0);
        }
    }
    //cout<<"loop:"<<loop;
    while(k%loop!=0){
        cnt+=a[cnt%n];
        k--;
    }
    //exit(0);
    Int sm1Loop=0;
    REP(i,loop){
        sm1Loop+=a[cnt%n];
        cnt+=a[cnt%n];
        k--;
    }
    cnt+=(k/loop)*sm1Loop;
    cout<<cnt<<"\n";
    exit(0);
}