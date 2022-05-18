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
set<string> st;Int K;string S;
Int N;
bool gone[9];
void dfs(int i, string s=""){
    //cout<<i<<","<<s<<"\n";
    if(i==N-1){
        //cout<<s<<"\n";
        st.insert(s);
    }
    REP(j,N){
        if(gone[j])continue;
        gone[j]=true;
        dfs(i+1, s+S[j]);
        gone[j]=false;
    }
}
int main(void){
    cin>>S;N=S.size(); cin>>K;
    REP(i,N){
        gone[i]=true;
        //cout<<S[i]<<"\n";
        string s0;s0.push_back(S[i]);
        dfs(0,s0);
        gone[i]=false;
    }
    vector<string> v(st.begin(),st.end());
    //cout<<v.size()<<"\n";
    //REP(i,v.size())cout<<v[i]<<"\n";
    //cout<<K<<"\n";
    cout<<v[K-1]<<"\n";
}