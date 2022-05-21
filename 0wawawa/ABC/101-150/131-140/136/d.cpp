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
typedef pair<ll,ll> P;
int main(void){
    string S;cin>>S;
    ll N=S.size();
    //ランレングス圧縮
    vector<P> v;
    for(ll i=0,n1=0,n2=0;i<N;n1=n2=0){
        while(S[i]=='R')n1++,i++;
        while(S[i]=='L')n2++,i++;
        v.push_back(make_pair(n1,n2));
    }
    /*//結果の確認
    for(auto r:v){
        cout<<'R'<<r.first<<'L'<<r.second;
    }cout<<"\n";*/

    ll ans[N];REP(i,N)ans[i]=0;
    ll n=0;
    for(auto r:v){
        ll len=r.first+r.second;
        ll idxR=n+r.first-1,idxL=idxR+1;
        if(len%2==0){//文字数が偶数
            ans[idxR]=ans[idxL]=len/2;
        }
        else if(len%2==1){//文字数が奇数
            if(r.first>r.second&&r.second%2==1){//lの長さ>rの長さが奇数
                ans[idxR]=(len-1)/2,ans[idxL]=(len+1)/2;
            }else if(r.first%2==1&&r.first<r.second){//lの長さが奇数<rの長さ
                ans[idxR]=(len+1)/2,ans[idxL]=(len-1)/2;
            }
            else if(r.first<r.second){//lの長さ<rの長さ
                ans[idxR]=(len-1)/2,ans[idxL]=(len+1)/2;
            }else if(r.first>r.second){//lの長さ>rの長さ
                ans[idxR]=(len+1)/2,ans[idxL]=(len-1)/2;
            }
        }
        n+=len;
    }
    REP(i,N){
        cout<<ans[i]<<" ";
    }cout<<"\n";
}
