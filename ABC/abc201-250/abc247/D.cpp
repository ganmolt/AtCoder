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
    Int Q;cin>>Q;

    deque<pair<Int,Int>> que;

    REP(i,Q){
        int q;cin>>q;
        if(q==1){
            Int x,c;cin>>x>>c;
            que.push_back({x,c});
        }else{
            Int c;cin>>c;
            Int out=0;
            while(c>0){
                auto r=que.front();que.pop_front();
                //cout<<"c:"<<c<<","<<"r:"<<r.second<<"\n";
                if(c>r.second){
                    c-=r.second;
                    out+=r.first*r.second;
                }else if(c==r.second){
                    out+=r.first*r.second;
                    c=0;
                }else{
                    out+=r.first*c;
                    Int newc=r.second-c;
                    c=0;
                    que.push_front({r.first,newc});
                }
            }
            cout<<out<<"\n";
        }
    }
}