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
#define dcml(n) fixed<<setprecision(n)
//CONST
//------------------------------------------
const ll INF=1010000000000000017LL;
const ll MOD=1000000007LL;
const ld EPS=1e-12;
const ld PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define  FORS(i,m,n) for(ll (i)=(m);   (i)<=(n); (i)++)
#define  RFOR(i,m,n) for(ll (i)=(n)-1; (i)>=(n); (i)--)
#define RFORS(i,m,n) for(ll (i)=(n);   (i)>(n);  (i)--)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
#define WREPS(i,in,j,jn) REPS(i,in)REPS(j,jn)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    ll N,K;cin>>N>>K;
    vector<ll> A(N);
    REP(i,N){cin>>A[i];A[i]--;}
    
    ll fi,li;//first, last

    vi v;//軌跡
    ll done[N+1];REP(i,N+1)done[i]=-1;//いつ行ったか
    ll tmp=0;//初期値=0
    v.push_back(0);
    REPS(i,N+1){
        tmp=A[tmp];v.push_back(tmp);
        if(done[tmp]==-1){
            done[tmp]=i;
        }else{
            li=i;fi=done[tmp];
            //cout<<"fi:"<<fi<<"li:"<<li<<"\n";
            break;
        }
    }

    if(K<N+1){//K<N+1の場合に限り
        REP(i,N){
            if(i==K){
                cout<<v[i]+1<<"\n";
                exit(0);
            }
        }
    }

    //cout<<v[fi]<<" "<<v[li]<<"\n";
    v.erase(v.begin(),v.begin()+fi);
    //cout<<v[0]<<" "<<v[v.size()-1]<<"\n";

    ll idx=K-fi;
    ll round=li-fi;
    //cout<<idx<<" "<<round<<"\n";
    cout<<v[idx%round]+1<<"\n";

}