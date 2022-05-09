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
    string s;cin>>s;
    int isIn[10];
    REP(i,s.size()){
        if(s[i]=='o')isIn[i]=1;
        else if(s[i]=='x')isIn[i]=-1;
        else isIn[i]=0;
    }

    Int ans=0;
    REP(k,10000){
        string strNum;
        if(k<10)strNum.push_back('0');
        if(k<100)strNum.push_back('0');
        if(k<1000)strNum.push_back('0');
        strNum+=to_string(k);
        Int num[4];
        REP(i,4)num[i]=(strNum[i]-'0');
        //---------------------------
        bool isInNum[10];REP(i,10)isInNum[i]=false;
        REP(i,4){
            isInNum[num[i]]=true;
        }

        bool ok=true;
        REP(i,10){
            if(isIn[i]==0)continue;
            if(isIn[i]==1&&isInNum[i]==true)continue;
            if(isIn[i]==-1&&isInNum[i]==false)continue;
            ok=false;
        }
        ans+=ok;
    }
    cout<<ans<<"\n";
}