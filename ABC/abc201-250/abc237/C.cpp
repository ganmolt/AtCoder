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
    string S;
    cin>>S;
    Int N=S.size();

    Int cntLastA=0,cntTopA=0;
    Int k=0;
    while(S[N-1-k++]=='a')cntLastA++;
    k=0;
    while(S[k++]=='a')cntTopA++;

    string newS;
    for(int i=0;i<cntLastA-cntTopA;i++)newS.push_back('a');

    REP(i,N)newS.push_back(S[i]);
    //cout<<newS<<"\n";

    Int nN=newS.size();
    REP(i,nN){
        //cout<<newS[i]<<","<<newS[nN-1-i]<<"\n";
        if(newS[i]!=newS[nN-1-i]){
            cout<<"No\n";
            exit(0);
        }
    }
    cout<<"Yes\n";
}