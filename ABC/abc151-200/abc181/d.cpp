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
vector<int> cnt(10);
bool b[1000];
void dfs(int s){
    if(s>=100){
        b[s]=true;
        return;
    }
    for(int i=1;i<=9;i++){
        if(cnt[i]==0)continue;
        cnt[i]--;
        dfs(s*10+i);
        cnt[i]++;
    }
    
}
int main(void){
    string s;cin>>s;

    if(s.size()<3){
        if(s.size()==1){
            if(s=="8")YES;
            NO;
        }else{
            if( ((s[0]-'0')*10+(s[1]-'0')) %8==0)YES;
            if( ((s[1]-'0')*10+(s[0]-'0')) %8==0)YES;
            NO;
        }
    }

    
    REP(i,s.size()){
        cnt[(s[i]-'0')]++;
    }

    dfs(0);
    //REP(i,1000)cout<<i<<":"<<b[i]<<"\n";
    for(int i=100;i<=999;i++){
        if(b[i]==true&&i%8==0){
            YES;
        }
    }
    NO;
}