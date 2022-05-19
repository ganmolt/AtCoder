//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long
#define Double long double
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
    Int N,K;cin>>N>>K;
    string S;cin>>S;

    vector<vector<Int>> c(110000,vector<Int>(26,-1));//i文字目以降にある文字で最初のjの文字のidx
    for(Int i=0;i<26;i++)c[N][i]=-1;
    for(Int i=N-1;i>=0;i--){
        for(Int j=0;j<26;j++){
            if((S[i]-'a')==j){
                c[i][j]=i;
            }
            else{
                c[i][j]=c[i+1][j];
            }
        }
    }

    string ans="";
    Int cnt=0;
    for(int i=0;i<N;i++){
        if(ans.size()==K)break;
        char cc='{';//zより大きい文字 'z':122,'{':123}
        Int mIdx=INF;
        for(int j=0;j<26;j++){
            if(c[i][j]<0)continue;
            if(cc>char('a'+j)){
                if(N-c[i][j]>=K-cnt){//有効な位置にあれば
                    cc=char('a'+j);
                    mIdx=c[i][j];
                }
            }
        }
        i=mIdx;
        ans.push_back(cc);cnt++;
    }
    cout<<ans<<"\n";

}
