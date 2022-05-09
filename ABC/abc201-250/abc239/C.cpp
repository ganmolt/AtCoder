//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    Int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<pair<Int,Int>> points1, points2;
    Int dx[8]={1,2,2,1,-1,-2,-2,-1};
    Int dy[8]={2,1,-1,-2,-2,-1,1,2};
    REP(i,8){
        points1.push_back({x1+dx[i],y1+dy[i]});
        points2.push_back({x2+dx[i],y2+dy[i]});
    }
    sort(points1.begin(),points1.end());
    sort(points2.begin(),points2.end());

    vector<pair<Int,Int>> p;

    set_intersection(points1.begin(),points1.end(),
                    points2.begin(),points2.end(),
                    back_inserter(p));
    
    if(p.size()!=0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
