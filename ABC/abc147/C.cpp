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
    Int N;cin>>N;
    vector<pair<int,int>> ppl[N];
    REP(i,N){
        int a;cin>>a;
        REP(j,a){
            int x,y;cin>>x>>y;x--;
            ppl[i].push_back({x,y});
        }
    }
    int ans=0;
    for(int bit=0;bit<(1<<N);bit++){
        bool ok=true;int cnt=0;
        for(int i=0;i<N;i++){
            //bitがついてれば正直者とする
            if(bit&(1<<i)){
                cnt++;
                for(auto r:ppl[i]){
                    if(r.second==1){//正直者が点灯していなかったら
                        if(!(bit&(1<<r.first)))ok=false;
                    }else{//unkindが点灯してたら
                        if(bit&(1<<r.first))ok=false;
                    }
                }
            }
        }
        if(ok)chmax(ans,cnt);
    }
    cout<<ans<<"\n";
}