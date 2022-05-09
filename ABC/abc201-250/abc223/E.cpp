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
    Int X,Y,T[3];cin>>X>>Y>>T[0]>>T[1]>>T[2];
    sort(T,T+sizeof(T)/sizeof(T[0]));

    do{
        Int dw1=0,dh1=0;
        Int W1=X,H1=Y;
        //cout<<"W1:"<<W1<<" H1:"<<H1<<"\n";
        REP(i,2){
            if(i==0){
                dw1=0;
                dh1=(T[0]+W1-1)/W1;
            }else{
                dw1=(T[0]+H1-1)/H1;
                dh1=0;
            }
            Int dw2=0,dh2=0;
            Int W2=X-dw1,H2=Y-dh1;
            //cout<<"W2:"<<W2<<" H2:"<<H2<<"\n";
            if(W2<=0||H2<=0){
                //cout<<"continue;\n";
                continue;
            }
            REP(j,2){
                if(j==0){
                    dw2=0;
                    dh2=(T[1]+W2-1)/W2;
                }else{
                    dw2=(T[1]+H2-1)/H2;
                    dh2=0;
                }
                Int dw3=0,dh3=0;
                Int W3=W2-dw2,H3=H2-dh2;
                //cout<<j<<": "<<"W3:"<<W3<<" H3:"<<H3<<"\n";
                if(W3<=0||H3<=0){
                    //cout<<"continue;\n";
                    continue;
                }
                REP(k,2){
                    if(k==0){
                        dw3=0;
                        dh3=(T[2]+W3-1)/W3;
                    }else{
                        dw3=(T[2]+H3-1)/H3;
                        dh3=0;
                    }
                    Int resW=W3-dw3;
                    Int resH=H3-dh3;
                    //cout<<"resW:"<<resW<<" resH:"<<resH<<"\n";
                    if(resW>=0&&resH>=0){
                        cout<<"Yes\n";
                        exit(0);
                    }
                }
            }
        }
    }while(next_permutation(T,T+sizeof(T)/sizeof(T[0])));
    cout<<"No\n";

}