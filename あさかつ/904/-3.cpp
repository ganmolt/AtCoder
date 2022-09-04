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
    char c[n][n]; REP(i,n)REP(j,n) cin >> c[i][j];

    if(n<6)NO;
    
    for(int i = 0; i < n; i++){
        int ans = 0;
        int drw = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int ln = 0;
        while(true){
            if(r > n) break;
            if(c[i][r] == '#'){
                cnt++;
                r++;
            }else{
                if(drw < 2){
                    cnt++;
                    r++;
                    drw++;
                }else{
                    if(c[i][l] == '.'){
                        drw--;
                        
                    }
                    cnt--;
                    l++;
                }
            }
            chmax(ans, cnt);
            if(ans >= 6)YES;
        }
    }

    for(int i = 0; i < n; i++){
        int ans = 0;
        int drw = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int ln = 0;
        while(true){
            if(r > n) break;
            if(c[r][i] == '#'){
                cnt++;
                r++;
            }else{
                if(drw < 2){
                    cnt++;
                    r++;
                    drw++;
                }else{
                    if(c[l][i] == '.'){
                        drw--;
                        
                    }
                    cnt--;
                    l++;
                }
            }
            chmax(ans, cnt);
            if(ans >= 6)YES;
        }
    }

    for(int i = 0; i < n; i++){
        int ans = 0;
        int drw = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int ln = 0;
        while(true){
            if(i + r > n) break;
            if(c[r][i+r] == '#'){
                cnt++;
                r++;
            }else{
                if(drw < 2){
                    cnt++;
                    r++;
                    drw++;
                }else{
                    if(c[l][i+l] == '.'){
                        drw--;
                        
                    }
                    cnt--;
                    l++;
                }
            }
            chmax(ans, cnt);
            if(ans >= 6)YES;
        }
    }

    for(int i = 0; i < n; i++){
        int ans = 0;
        int drw = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int ln = 0;
        while(true){
            if(i + r > n || i - r < 0) break;
            if(c[r][i-r] == '#'){
                cnt++;
                r++;
            }else{
                if(drw < 2){
                    cnt++;
                    r++;
                    drw++;
                }else{
                    if(c[l][i-l] == '.'){
                        drw--;
                        
                    }
                    cnt--;
                    l++;
                }
            }
            chmax(ans, cnt);
            if(ans >= 6)YES;
        }
    }
    
    for(int i = 0; i < n; i++){
        int ans = 0;
        int drw = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int ln = 0;
        while(true){
            //if(l==0 && r==0)cout << (n-1)-r << "," << i-r << "\n";
            if((n-1)-r < 0 || i - r < 0) break;
            //cout << c[(n-1)-r][i-r];
            if(c[(n-1)-r][i-r] == '#'){
                cnt++;
                r++;
                
            }else{
                if(drw < 2){
                    cnt++;
                    r++;
                    drw++;
                }else{
                    if(c[(n-1)-l][i-l] == '.'){
                        drw--;
                        
                    }
                    cnt--;
                    l++;
                }
            }
            //cout << l << "," << r << ": " << cnt << " drw:" << drw << "\n";
            chmax(ans, cnt);
            if(ans >= 6)YES;
        }//cout << "\n";
    }
    for(int i = 0; i < n; i++){
        int ans = 0;
        int drw = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int ln = 0;
        while(true){
            if((n-1)-r < 0 || i + r > n) break;
            if(c[(n-1)-r][i+r] == '#'){
                cnt++;
                r++;
            }else{
                if(drw < 2){
                    cnt++;
                    r++;
                    drw++;
                }else{
                    if(c[(n-1)-l][i+l] == '.'){
                        drw--;
                        
                    }
                    cnt--;
                    l++;
                }
            }
            chmax(ans, cnt);
            if(ans >= 6)YES;
        }
    }
    
    NO;
}