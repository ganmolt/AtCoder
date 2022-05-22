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
    Int d,x;cin>>d>>x;
    d*=10;

    string CD[18]={"N","NNE","NE","ENE","E","ESE","SE","SSE",
                    "S","SSW","SW","WSW","W","WNW","NW","NNW","N","C"};

    vector<int> DS = {1125,  3375,  5625,  7875,  10125, 12375,
	                       14625, 16875, 19125, 21375, 23625, 25875,
	                       28125, 30375, 32625, 34875
	                      };

    vector<double> SS = {
		0.25 * 60,  1.55 * 60,  3.35 * 60,  5.45 * 60,
		7.95 * 60,  10.75 * 60, 13.85 * 60, 17.15 * 60,
		20.75 * 60, 24.45 * 60, 28.45 * 60, 32.65 * 60
	};
    int i=0;
    while(d>=DS[i]&&i<16)i++;
    int j=0;
    while(x>=SS[j]&&j<12)j++;
    if(j==0)i=17;

    cout<<CD[i]<<" "<<j<<"\n";
}