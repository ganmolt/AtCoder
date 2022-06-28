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
    vector<int> a[n];
    REP(i,n){
        REP(j,n-1){
            int aa;cin>>aa;aa--;
            a[i].push_back(aa);
        }
    }

    vector<int> idx(n,0);
    int d=0;
    while(true){
        bool done[n];REP(i,n)done[i]=false;
        REP(i,n){
            if(idx[i]==n-1)continue;
            int a0=a[i][idx[i]];
            if(done[i]||done[a0])continue;
            if(a[a0][idx[a0]]==i){

                idx[i]++;
                idx[a0]++;
                
                done[i]=true;
                done[a0]=true;
                
            }
        }
        int c1=0;
        REP(i,n){
            //cout<<i<<": "<<idx[i]<<"\n";
            if(idx[i]==n-1)c1++;
        }
        if(c1==n)break;
        //cout<<d<<":"<<c1<<"\n";

        int c2=0;
        REP(i,n)c2+=done[i];
        if(c2==0){
            d=-2;
            break;
        }
        d++;
    }
    cout<<d+1<<"\n";
}
