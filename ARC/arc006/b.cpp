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
    int n,l;cin>>n>>l;cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> s(l);
    REP(i,l){
        getline(cin,s[i],'\n');
    }
    string g;getline(cin,g);
    int goal=g.find('o');
    int pos=goal;
    for(int i=l-1;i>=0;i--){
        if(pos+1<2*n-1&&s[i][pos+1]=='-')pos+=2;
        else if(0<pos-1&&s[i][pos-1]=='-')pos-=2;
    }
    cout<<pos/2+1<<"\n";
}