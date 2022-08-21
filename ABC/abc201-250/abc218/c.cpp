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
    int n; cin >> n;
    char s[n][n]; REP(i,n)REP(j,n) cin >> s[i][j];
    char t[n][n]; REP(i,n)REP(j,n) cin >> t[i][j];

    int s_a = -1, s_b = -1, s_c = -1, s_d = -1;
    int t_a = -1, t_b = -1, t_c = -1, t_d = -1;
    REP(i,n)REP(j,n){
        if(s[i][j] == '#' && s_a == -1) s_a = i;
        if(s[i][j] == '#') s_b = i;

        if(t[i][j] == '#' && t_a == -1) t_a = i;
        if(t[i][j] == '#') t_b = i;
    }

    REP(j,n)REP(i,n){
        if(s[i][j] == '#' && s_c == -1) s_c = j;
        if(s[i][j] == '#') s_d = j;

        if(t[i][j] == '#' && t_c == -1) t_c = j;
        if(t[i][j] == '#') t_d = j;
    }

    vector<vector<char>> v1;
    for(int i = s_a; i <= s_b; i++){
        vector<char> v;
        for(int j = s_c; j <= s_d; j++){
            //cout << s[i][j];
            v.push_back(s[i][j]);
        } //cout << "\n";
        v1.push_back(v);
    }

    vector<vector<char>> v2;
    for(int i = t_a; i <= t_b; i++){
        vector<char> v;
        for(int j = t_c; j <= t_d; j++){
            //cout << s[i][j];
            v.push_back(t[i][j]);
        } //cout << "\n";
        v2.push_back(v);
    }
    
//-------------------------------------------------------
    if(v1.size() == v2.size() && v1[0].size() == v2[0].size()){
        bool ok = true;
        REP(i,v1.size()){
            REP(j,v1[0].size()){
                if(v1[i][j] == t[t_a + i][t_c + j]){
                    continue;
                }
                ok = false;
            }
        }
        if(ok) YES;
    }
    if(v1.size() == v2[0].size() && v1[0].size() == v2.size()){
        bool ok = true;
        REP(i,v1.size()){
            REP(j,v1[0].size()){
                if(v1[i][j] == t[t_b - j][t_c + i]){
                    continue;
                }
                ok = false;
            }
        }
        if(ok) YES;
    }

    if(v1.size() == v2.size() && v1[0].size() == v2[0].size()){
        bool ok = true;
        REP(i,v1.size()){
            REP(j,v1[0].size()){
                if(v1[i][j] == t[t_b - i][t_d - j]){
                    continue;
                }
                ok = false;
            }
        }
        if(ok) YES;
    }

    if(v1.size() == v2[0].size() && v1[0].size() == v2.size()){
        bool ok = true;
        REP(i,v1.size()){
            REP(j,v1[0].size()){
                if(v1[i][j] == t[t_a + j][t_d - i]){
                    continue;
                }
                ok = false;
            }
        }
        if(ok) YES;
    }
    NO;
}
