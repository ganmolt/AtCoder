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
    Int N, P, Q, R; cin >> N >> P >> Q >> R;
    vector<Int> a(N);
    REP(i,N) cin >> a[i];

    Int s1=a[0],s2=a[1],s3=a[2], i1=0,i2=1,i3=2,i4=3;
    while(true) {
        if( s1 == P && s2 == Q && s3 == R ) YES;
        if(s1 < P) {
            s1 += a[i2];
            s2 -= a[i2];
            i2++;
        }else if(s1 > P){
            s1 -= a[i1];
            i1++;
        }
        if(i1 == i2){
            s1 += a[i2];
            s2 -= a[i2];  
            i2++;
        }
        if(i2 == i3){
            s2 += a[i3];
            s3 -= a[i3];
            i3++;
        }
        if(i3 == i4){
            if( i4 == N )NO;
            s3 += a[i4];
            i4++;
        }


        if(s2 < Q) {
            s2 += a[i3];
            s3 -= a[i3];
            i3++;
        }else if(s2 > Q){
            s2 -= a[i2];
            s1 += a[i2];
            i2++;
        }
        if(i2 == i3){
            s2 += a[i3];
            s3 -= a[i3];
            i3++;
        }
        if(i3 == i4){
            if( i4 == N )NO;
            s3 += a[i4];
            i4++;
        }

        if(s3 < R) {
            if( i4 == N )NO;
            s3 += a[i4];
            i4++;
        }else if(s3 > R){
            s3 -= a[i3];
            s2 += a[i3];
            i3++;
        }
        if(i3 == i4){
            if( i4 == N )NO;
            s3 += a[i4];
            i4++;
        }
    }
}