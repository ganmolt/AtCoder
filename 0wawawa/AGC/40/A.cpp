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
    if(S[0]=='>')v.push_back({'<',0});
    for(ll i=1,cnt=1;i<=N;i++){
        if(i==N){//最後
            v.push_back({prev,cnt});
            break;
        }
        while(S[i]==prev){cnt++;i++;}//数え上げ
        v.push_back({prev,cnt});
        cnt=1;prev=S[i];//初期化
    }
    if(S[S.size()-1]=='<')v.push_back({'>',0});
    return v;
}
typedef pair<ll,ll> P;
int main(void){
    string S;cin>>S;
    vector<_RLE> v=RLE(S);
    ll N=v.size();
    vector<P> v2;
    REP(i,N){
        ll c1=v[i].len,c2=v[++i].len;
        v2.push_back(make_pair(c1,c2));
    }
    ll ans=0;
    REP(i,v2.size()){
        ll l1=v2[i].first,l2=v2[i].second;
        ll m=min(l1,l2);
        ans+=l1*(1+l1)*1/2;ans+=l2*(1+l2)*1/2;ans-=m;
        //cout<<v2[i].first<<v2[i].second<<"\n";
    }
    cout<<ans<<"\n";
}