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
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    REP(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i], a[i]--, b[i]--;

    vector<int> v(10); 
    REP(i,10){
        if(i < m) v[i] = i+1;
        else v[i] = -1;
    }
    int ans = 0;
    do{
        REP(i,10)cout<<v[i]<<" ";cout<<"\n";
        bool f = false;
        REP(i,n-1) if(v[i+1] != -1 && v[i] > v[i+1]){ f=true; break; }
        if(f) continue;
        int sm = 0;
        REP(i,q){
            //cout << "v["<<b[i]<<"]" << v[b[i]]<<"-" << "v["<<a[i]<<"]"<<v[a[i]]<<"=" << c[i];
            if(v[a[i]] == -1 || v[b[i]] == -1){
                //cout << "\n";
                continue;
            }
            if(v[b[i]]-v[a[i]] == c[i]){
                sm += d[i];
                //cout << ": " << d[i];
            }
            //cout << "\n";
        }
        //cout << ": " << sm << "\n";
        chmax(ans, sm);
    }
    while(next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
}