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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
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
    ll N,M;cin>>N>>M;
    char A[2*N][M];
    REP(i,2*N){
        REP(j,M){
            cin>>A[i][j];
        }
    }

    struct P{
        ll n=-1,win=0;
    };
    vector<P> p(2*N);
    REP(i,2*N)p[i].n=i;

    REP(i,M){
        sort(p.begin(),p.end(), [](P const& l, P const& r){
            if(l.win==r.win)return l.n<r.n;
            return l.win>r.win;
        });
        for(int k=0;k<2*N;k+=2){
            ll n1=p[k].n,n2=p[k+1].n;
            //cout<<n1<<"."<<p[k].win<<A[n1][i]<<" vs "<<n2<<"."<<p[k+1].win<<A[n2][i]<<" ";
            if(A[n1][i]=='G'&&A[n2][i]=='C')p[n1].win++;
            else if(A[n1][i]=='G'&&A[n2][i]=='P')p[k+1].win++;
            else if(A[n1][i]=='C'&&A[n2][i]=='G')p[k+1].win++;
            else if(A[n1][i]=='C'&&A[n2][i]=='P')p[k].win++;
            else if(A[n1][i]=='P'&&A[n2][i]=='G')p[k].win++;
            else if(A[n1][i]=='P'&&A[n2][i]=='C')p[k+1].win++;
        }
    }
    /*
    sort(p.begin(),p.end(), [](P const& l, P const& r){
        return l.n<r.n;
    });*/
    sort(p.begin(),p.end(), [](P const& l, P const& r){
        if(l.win==r.win)return l.n<r.n;
        return l.win>r.win;
    });
    REP(i,2*N){
        cout<<p[i].n+1<<"."<<p[i].win<<"\n";
    }
}