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
Int N,M;
vector<vector<int>> v(11,vector<int>(11));
bool no[11][11];
Int ans=INF;
bool gone[11];
void dfs(int j, Int sm, int last){//cout<<"\n";
    //cout<<"第"<<j+1<<"区(score: "<<sm<<"):"<<last+1<<"=>";
    if(j+1==N){
        //cout<<"更新:"<<sm<<"\n";
        chmin(ans,sm);
        return;
    }
    REP(i,N){
        
        if(gone[i])continue;
        if(no[last][i]||no[i][last])continue;
        //cout<<i+1<<","<<j+1+1;
        //cout<<i<<",";
        gone[i]=true;
        //cout<<" "<<sm+v[i][j+1]<<"\n";
        dfs(j+1,sm+v[i][j+1],i);
        gone[i]=false;
    }
    return;
}

void solve(){
    REP(i,N){
        gone[i]=true;
        dfs(0,v[i][0],i);
        gone[i]=false;
    }
    
    cout<<(ans==INF?-1:ans)<<"\n";
}

int main(void){
    cin>>N;
    REP(i,N)REP(j,N)cin>>v[i][j];
    cin>>M;
    REP(i,M){
        int x,y;cin>>x>>y;x--;y--;
        no[x][y]=true;
    }
    solve();
}