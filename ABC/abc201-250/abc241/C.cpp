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
    string S[N];
    REP(i,N)cin>>S[i];

    //横向き
    REP(i,N){
        bool last=false;
        REP(j,N){
            if(j+5>=N)break;
            Int cnt=0;
            for(int k=j;k<j+6;k++){
                //cout<<i<<","<<k<<" ";
                if(S[i][k]=='#')cnt++;
            }//cout<<"\n";
            if(cnt>=4){
                cout<<"Yes\n";
                exit(0);
            }
        }
    }
    //縦
    REP(i,N){
        bool last=false;
        REP(j,N){
            if(j+5>=N)break;
            Int cnt=0;
            for(int k=j;k<j+6;k++){
                //cout<<k<<","<<i<<" ";
                if(S[k][i]=='#')cnt++;
            }//cout<<"\n";
            if(cnt>=4){
                cout<<"Yes\n";
                exit(0);
            }
        }
    }
    REP(i,N){
        REP(j,N){
            if(i+5>=N||j+5>=N)break;
            Int cnt=0;
            for(int k=0;k<6;k++){
                //cout<<i+k<<","<<j+k<<" ";
                if(S[i+k][j+k]=='#')cnt++;
            }//cout<<"\n";
            if(cnt>=4){
                cout<<"Yes\n";
                exit(0);
            }
        }
    }
    REP(i,N){
        REP(j,N){
            //cout<<i<<","<<j<<"\n";
            if(i+5>=N||j-5<0)continue;
            Int cnt=0;
            for(int k=0;k<6;k++){
                //cout<<i+k<<","<<j-k<<" ";
                if(S[i+k][j-k]=='#')cnt++;
            }//cout<<"\n";
            if(cnt>=4){
                cout<<"Yes\n";
                exit(0);
            }
        }
    }
    cout<<"No\n";
}