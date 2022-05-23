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
    Int n;cin>>n;
    if(n<100)cout<<n<<"\n";
    else if(n>=9876543211){
        //nの桁数とって、最初のぞろ目
        string sn=to_string(n);
        string ssn;REP(i,sn.size())ssn.push_back(sn[0]);
        if(ssn<sn)sn[0]++;
        //n=stoll(sn);
        REP(i,sn.size())cout<<sn[0];cout<<"\n";
    }else{
        //cout<<"*::::"<<"\n";
        string sn=to_string(n);
        for(;sn[0]-'0'<=9;){
            for(int d=-8;d<9;d++){
                //cout<<d<<"\n";
                if(0<=(sn[0]-'0')+d*(sn.size()-1)
                    &&(sn[0]-'0')+d*(sn.size()-1)<=9){
                    //ok
                    //cout<<d<<"_n";
                    string news;
                    for(int k=0;k<sn.size();k++){
                        news.push_back(sn[0]+d*k);
                    }
                    if(n<=stoll(news)){
                        cout<<news<<"\n";
                        return 0;
                    }
                }
            }
            sn[0]++;
            for(int i=1;i<sn.size();i++)sn[i]='0';
            //cout<<sn<<"\n";

        }
    }
    //cout<<n<<"\n";
}