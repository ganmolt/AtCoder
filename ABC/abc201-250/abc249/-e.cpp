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
Int dp[3010][1510][26];
int main(void){
    int n;Int p;cin>>n>>p;
    if(n<=2)cout<<0<<"\n",exit(0);
    REP(i,26)dp[0][0][i]=1;
    Int K=(n)/2;
    Int smz=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<K;k++){
            Int sm=0;
            for(int m=0;m<26;m++){
                if(i!=0&&k!=0)dp[i][k][m]=(dp[i][k][m]+smz-dp[i-1][k-1][m])%p;
                sm+=dp[i][k][m];
                dp[i+1][k][m]=dp[i][k][m];
            }
            smz=sm;
        }
    }
    Int ans=0;
    // for(int i=0;i<n;i++){
    //     for(int k=0;k<K;k++){
    //         for(int m=0;m<26;m++){
    //             //cout<<dp[i][k][m]<<" ";
    //         }//cout<<"\n";
    //     }//cout<<"\n";
    // }//cout<<"\n";
    for(int k=0;k<K;k++){
        for(int m=0;m<26;m++){
            ans=(ans+dp[n][k][m]+p)%p;
        }
    }
    cout<<ans<<"\n";
}
