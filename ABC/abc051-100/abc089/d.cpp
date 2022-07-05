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
//1-idx
int main(void){
    int h,w,D;cin>>h>>w>>D;
    int a[h][w];REP(i,h)REP(j,w)cin>>a[i][j];
    int q;cin>>q;
    vector<int> l(q),r(q);REP(i,q)cin>>l[i]>>r[i];

    int n=h*w;

    pair<int,int> xy[n+1];
    REP(i,h)REP(j,w){
        xy[ a[i][j] ]={i+1,j+1};
    }

    int d[n+1+1];
    for(int k=0;k<D;k++){
        for(int i=n-k;i>=1;i-=D){
            if(i+D>=n+1)d[i]=0;
            else{
                int x1=xy[i].first;
                int y1=xy[i].second;
                int x2=xy[i+D].first;
                int y2=xy[i+D].second;
                int dist=abs(x1-x2)+abs(y1-y2);
                d[i]=dist+d[i+D];
            }
        }
    }
    REP(i,q){
        //cout<<d[l[i]]<<","<<d[r[i]]<<"\n";
        cout<<d[l[i]]-d[r[i]]<<"\n";
    }
}