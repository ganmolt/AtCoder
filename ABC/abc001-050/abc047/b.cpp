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
    int w,h,n;cin>>w>>h>>n;
    vector<int> x(n),y(n),a(n);REP(i,n)cin>>x[i]>>y[i]>>a[i];
    bool b[w][h];REP(i,w)REP(j,h)b[i][j]=1;
    REP(i,n){
        if(a[i]==1){
            for(int p=x[i]-1;p>=0;p--){
                REP(q,h){
                    b[p][q]=0;
                }
            }
        }
        if(a[i]==2){
            for(int p=x[i];p<w;p++){
                REP(q,h){
                    b[p][q]=0;
                }
            }
        }
        if(a[i]==3){
            for(int q=y[i]-1;q>=0;q--){
                REP(p,w){
                    b[p][q]=0;
                }
            }
        }
        if(a[i]==4){
            for(int q=y[i];q<h;q++){
                REP(p,w){
                    b[p][q]=0;
                }
            }
        }
    }
    int cnt=0;
    REP(j,h){
        REP(i,w){
            cnt+=b[i][j];
        }
    }
    cout<<cnt<<"\n";
}