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
    int Q;cin>>Q;
    vector<int> q[Q];
    REP(i,Q){
        int qq;cin>>qq;
        q[i].push_back(qq);
        if(qq==1){
            int x;cin>>x;
            q[i].push_back(x);
        }else if(qq==2){
            int x,c;cin>>x>>c;
            q[i].push_back(x);
            q[i].push_back(c);
        }else{

        }
    }

    map<int,int> m;
    REP(i,Q){
        if(q[i][0]==1){
            m[q[i][1]]++;
        }else if(q[i][0]==2){
            m[q[i][1]]-=min(m[q[i][1]],q[i][2]);
            if(m[q[i][1]]==0)m.erase(q[i][1]);
        }else{
            auto mm=m.begin();
            auto MM=m.end();MM--;
            cout<<MM->first-mm->first<<"\n";
            
        }
    }
}