//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
//-----------------------------------------
#define dcml(n) fixed<<setprecision(n)
using namespace std;

struct Edge{
    int from,to;
};
vector<Edge> G[100];
bool done[100];

bool f;
void dfs(int i,int z){
    //cout<<"now "<<i<<":\n";
    done[i]=true;//探索済みにする
    for(auto r:G[i]){
        if(r.to==z)continue;
        //cout<<r.to <<" is "<<done[r.to]<<" \n";
        //直近に訪れてない場合
        if(done[r.to]){//探索済みなら
            f=false;
            //cout<<"f is"<<f<<"\n";
            continue;
        }
        dfs(r.to,i);
    }
}

int main(void){
    ll N,M;cin>>N>>M;
    REP(i,N)done[i]=false;
    int a,b;
    REP(i,M){
        cin>>a>>b;a--;b--;
        G[a].push_back({a,b});
        G[b].push_back({b,a});
    }
    ll cnt=0;
    RREP(i,N){
        if(done[i])continue;
        f=true;
        dfs(i,-1);
        //cout<<"res: "<<f<<" ///loop\n";
        if(f){
            cnt++;
            //cout<<i<<"isOK\n";
        }
    }
    cout<<cnt<<"\n";
}