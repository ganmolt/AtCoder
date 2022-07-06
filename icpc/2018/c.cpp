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
    while(true){
        Int b;cin>>b;
        if(b==0)break;
        Int l=1,r=2;
        Int ans=1;
        Int low=b;
        while(true){
            //cout<<r<<" ";
            if(r>1e9)break;
            while(r<l)r++;
            Int n=(r-l);
            Int c=n*(l+(r-1))/2;
            //cout<<"n: "<<n<<", c: "<<c<<"(l,r): ("<<l<<","<<r<<")\n";
            if(c==b){
                //cout<<"n: "<<n<<", c: "<<c<<"(l,r): ("<<l<<","<<r<<")\n";
                if(ans<n){
                    ans=n;
                    low=l;
                }
                r++;
            }
            else if(b<c)l++;
            else r++;
        }
        cout<<low<<" "<<ans<<"\n";
    }
}
    
