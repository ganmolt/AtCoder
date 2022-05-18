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
    vector<Int> X(N),Y(N);
    REP(i,N){
        Int x,y;cin>>x>>y;
        X[i]=x;Y[i]=y;

    }
    string S;
    cin>>S;

    vector<pair<Int,Int>> YX_R,YX_L;
    REP(i,N){
        if(S[i]=='R'){
            YX_R.push_back({Y[i],X[i]});
        }else{
            YX_L.push_back({Y[i],X[i]});
        }
    }
    sort(YX_R.begin(),YX_R.end());
    sort(YX_L.begin(),YX_L.end());
    Int nowY=0;Int i=0,j=0;
    Int s1=YX_R.size(),s2=YX_L.size();
    while(i<s1&&j<s2){
        while(i+1<s1&&YX_R[i].first<YX_L[j].first)i++;
        while(j+1<s2&&YX_R[i].first>YX_L[j].first)j++;
        if(YX_R[i].first==YX_L[j].first){
            if(YX_R[i].second<YX_L[j].second){
                cout<<"Yes\n";
                exit(0);
            }
            if(i+1==s1&&j+1==s2){cout<<"No\n";exit(0);}
            else if(i+1==s1)j++;
            else if(j+1==s2)i++;

            if(YX_R[i+1].first<YX_L[j+1].first)i++;
            else j++;
            continue;
        }i++;
    }
    cout<<"No\n";
}
