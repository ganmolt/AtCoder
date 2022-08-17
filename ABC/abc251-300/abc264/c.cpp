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
    int h1, w1; cin >> h1 >> w1;
    Int a1[h1][w1]; REP(i,h1)REP(j,w1) cin >> a1[i][j];

    int h2, w2; cin >> h2 >> w2;
    Int a2[h2][w2]; REP(i,h2)REP(j,w2) cin >> a2[i][j];
    vector<vector<Int>> v0(h2, vector<Int>(w2));
    REP(i,h2)REP(j,w2)v0[i][j] = a2[i][j];

    for(int bit = 0; bit < (1<< (h1 + w1)); bit++){
        int ch = 0, cw = 0;
        vector<bool> bh(h1, false);
        vector<bool> bw(w1, false);
        for(int i = 0; i < (h1 + w1); i++){
            if( (bit>>i)&1 ){
                //cout << 1;
                if(i < h1) bh[i] = true, ch++;
                else bw[i-h1] = true, cw++;
            }else{
                //cout << 0;
            }
        }//cout << "\n";

        if(ch != h2) continue;
        if(cw != w2) continue;
        vector<vector<Int>> vp;//(ch, vector<Int>(cw));
        REP(i, h1){
            if(bh[i] == false) continue;
            vector<Int> vc;
            REP(j, w1){
                if(bw[j] == false) continue;
                vc.push_back(a1[i][j]);
                //cout << a1[i][j] << " ";
            }//cout<<"\n";
            vp.push_back(vc);
        }
        if(vp == v0)YES;
    }
    NO;
}