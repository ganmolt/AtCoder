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
    string s; cin >> s;
    if(s[0] == '1') NO;

    bool is[7];REP(i,7) is[i] = true;
    if(s[6] == '0') is[0] = false;
    if(s[3] == '0') is[1] = false;
    if(s[1] == '0' && s[7] == '0') is[2] = false;
    if(s[0] == '0' && s[4] == '0') is[3] = false;
    if(s[2] == '0' && s[8] == '0') is[4] = false;
    if(s[5] == '0') is[5] = false;
    if(s[9] == '0') is[6] = false;

    // REP(i,7)cout << is[i] << ", ";

    bool existsEmptyLane = false;
    bool START = true;
    REP(i,7){
        // cout << i << ": ";
        if(START){
            if(is[i] == false){
            }else{
                START = false;
            }
            continue;
        }
        // cout << "body";
        if(existsEmptyLane && is[i] == true){
            YES;
        }
        if(is[i] == false){
            existsEmptyLane = true;
            // cout << "emptylane!";
            continue;

        }
        // cout << "\n";
    }
    NO;
}