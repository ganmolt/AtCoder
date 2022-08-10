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
Int a[1100][1100];
int main(void){
    int h, w; cin >> h >> w;
    REP(i,h){
        REP(j,w){
            cin >> a[i][j];
        }
    }
    vector<pair<Int,int>> idx(h*w);
    REP(i,h){
        REP(j,w){
            idx[i*w + j] = {a[i][j], i*w + j};
        }
    }

    sort(idx.begin(), idx.end());

    vector<Int> val(h*w, 1);

    for(auto r:idx){
        //r.second
        int x = r.second / w;
        int y = r.second % w;
        //cout<<"("<<r.first<<": "<<x<<","<<y<<") => ";
        pair<int,int> to[4] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        

        REP(i,4){
            int nx = x + to[i].first;
            int ny = y + to[i].second;
            if( 1 &&
            (0 <= nx && nx < h) &&
            (0 <= ny && ny < w)
            ){}else continue;

            
            if(r.first < a[nx][ny]){
            }else continue;

            //cout<<"("<<a[nx][ny]<<": "<<nx<<","<<ny<<")"<<", ";

            val[nx*w + ny] += val[r.second];
            val[nx*w + ny] %= MOD;
        }//cout<<"\n";
    }
    
    Int ans=0;
    REP(i,h*w){
        //cout << i << ":" << val[i] << "\n";
        ans = (ans + val[i]) % MOD;
    }
    cout<<ans<<"\n";
}

