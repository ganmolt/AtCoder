//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define ll long long
#define ld long double
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
//-----------------------------------------
#define dcml(n) fixed<<setprecision(n)
using namespace std;
struct _RLE{ char c; ll len; };
vector<_RLE> RLE(string S){
    ll N=S.size();
    vector<_RLE> v;
    char prev=S[0];
    for(ll i=1,cnt=1;i<=N;i++){
        if(i==N){//最後
            v.push_back({prev,cnt});
            break;
        }
        while(S[i]==prev){cnt++;i++;}//数え上げ
        v.push_back({prev,cnt});
        cnt=1;prev=S[i];//初期化
    }
    return v;
}
int main(void){
    string S;cin>>S;
    //ランレングス圧縮
    vector<_RLE> v=RLE(S);
    for(auto r:v){
        cout<<r.c<<r.len;
    }cout<<"\n";
}