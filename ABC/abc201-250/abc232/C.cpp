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
    Int N,M;cin>>N>>M;
    vector<vector<bool>> x(N,vector<bool>(N)), y(N,vector<bool>(N));
    REP(i,M){
        int a,b;cin>>a>>b;a--;b--;
        x[a][b]=x[b][a]=true;
    }
    REP(i,M){
        int a,b;cin>>a>>b;a--;b--;
        y[a][b]=y[b][a]=true;
    }
    vector<int> p(N);
    iota(p.begin(),p.end(),0);
    do{
        bool ok=true;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(x[p[i]][p[j]]!=y[i][j]){
                    ok=false;
                }
            }
        }
        if(ok){
            cout<<"Yes\n";
            exit(0);
        }

    }while(next_permutation(p.begin(),p.end()));
    cout<<"No\n";
}