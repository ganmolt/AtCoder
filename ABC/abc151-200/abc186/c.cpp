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
vector<int> to8(int x){
    vector<int> ret;
    while(x>0){
        ret.push_back(x%8);
        x/=8;
    }reverse(ret.begin(),ret.end());
    return ret;
}
bool is7(int x){
    string s=to_string(x);
    REP(i,s.size()){
        if(s[i]!='7')continue;
        return true;
    }
    return false;
}
bool is7(vector<int> x){
    REP(i,x.size()){
        if(x[i]!=7)continue;
        return true;
    }
    return false;
}
bool ok8[100001],ok10[100001];
int main(void){
    int n;cin>>n;
    //vector<int> v=to7(n);
    //REP(i,v.size())cout<<v[i];cout<<"\n";
    for(int i=1;i<=n;i++){
        if(!is7(i))ok10[i]=true;
        if(!is7(to8(i)))ok8[i]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        //cout<<i<<",";
        //REP(j,to8(i).size())cout<<to8(i)[j];cout<<"\n";
        if(ok10[i]&&ok8[i]){
            //cout<<i<<",";
            //REP(j,to7(i).size())cout<<to8(i)[j];cout<<"\n";
            ans++;
        }
    }
    cout<<ans<<"\n";
}
