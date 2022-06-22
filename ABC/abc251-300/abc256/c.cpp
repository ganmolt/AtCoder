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
    int h1,h2,h3,w1,w2,w3;
    cin>>h1>>h2>>h3>>w1>>w2>>w3;
    Int ans=0;
    for(int i11=1;i11<=30;i11++){
        for(int i12=1;i12<=30;i12++){
            for(int i21=1;i21<=30;i21++){
                for(int i22=1;i22<=30;i22++){
                    int i13=h1-i11-i12;
                    if(i13<=0)continue;
                    int i23=h2-i21-i22;
                    if(i23<=0)continue;

                    int i31=w1-i11-i21;
                    if(i31<=0)continue;
                    int i32=w2-i12-i22;
                    if(i32<=0)continue;

                    int i33w=w3-i13-i23;
                    int i33h=h3-i31-i32;
                    if(i33w<=0||i33h!=i33w)continue;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}