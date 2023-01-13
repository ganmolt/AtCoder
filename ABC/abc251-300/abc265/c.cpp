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
    int h, w; cin >> h >> w;

    vector<vector<char>> G(h, vector<char>(w));
    REP(i,h){
        REP(j,w) cin >> G[i][j];
    }

    bool gone[h][w];
    REP(i,h)REP(j,w) gone[i][j] = false;

    int x = 0, y = 0;
    while(true) {   
        if(gone[x][y]) break;
        gone[x][y] = true;

        if( G[x][y] == 'U' ){
            if( x == 0 ){
                cout << x+1 << " " << y+1 << "\n";
                exit(0);
            }
            x--;
            
        }
        else if( G[x][y] == 'D' ){
            if( x == h-1 ){
                cout << x+1 << " " << y+1 << "\n";
                exit(0);
            }
            x++;
        }
        else if( G[x][y] == 'L' ){
            if( y == 0 ){
                cout << x+1 << " " << y+1 << "\n";
                exit(0);
            }
            y--;
        }
        else if( G[x][y] == 'R' ){
            if( y == w-1 ){
                cout << x+1 << " " << y+1 << "\n";
                exit(0);
            }
            y++;
        }
    }
    cout << "-1\n";
}
