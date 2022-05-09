//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
#include <atcoder/all>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
using namespace atcoder;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
Int mod=998244353;
using mint=modint998244353;

mint solve(Int x){
    mint ans=mint(x)*(x+1)/2;
    if(x>=10)ans-=mint(9)*(x-9);
    if(x>=100)ans-=mint(90)*(x-99);
    if(x>=1000)ans-=mint(900)*(x-999);
    if(x>=10000)ans-=mint(9000)*(x-9999);
	if(x>=100000)ans-=mint(90000)*(x-99999);
	if(x>=1000000)ans-=mint(900000)*(x-999999);
	if(x>=10000000)ans-=mint(9000000)*(x-9999999);
	if(x>=100000000)ans-=mint(90000000)*(x-99999999);
	if(x>=1000000000)ans-=mint(900000000)*(x-999999999);
	if(x>=10000000000)ans-=mint(9000000000)*(x-9999999999);
	if(x>=100000000000)ans-=mint(90000000000)*(x-99999999999);
	if(x>=1000000000000)ans-=mint(900000000000)*(x-999999999999);
	if(x>=10000000000000)ans-=mint(9000000000000)*(x-9999999999999);
	if(x>=100000000000000)ans-=mint(90000000000000)*(x-99999999999999);
	if(x>=1000000000000000)ans-=mint(900000000000000)*(x-999999999999999);
	if(x>=10000000000000000)ans-=mint(9000000000000000)*(x-9999999999999999);
	if(x>=100000000000000000)ans-=mint(90000000000000000)*(x-99999999999999999);
	if(x>=1000000000000000000)ans-=mint(900000000000000000)*(x-999999999999999999);

    return ans;

}
int main(void){
    Int N;cin>>N;
    cout<<solve(N).val()<<"\n";

}
