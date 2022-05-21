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
int main(void){
    ll N,M;cin>>N>>M;
    ll cnt=0;
    if(N%2==1){
        if((N/2)%2==0){
            ll l=0,r=(N/2-1);
            REP(i,N/2){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+1==r)break;
                l++;r--;
            }
            l=N/2,r=N-1;
            REP(i,N/2){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+2==r)break;
                l++;r--;
            }
        }else{
            ll l=0,r=(N/2);
            REP(i,N/2){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+1==r)break;
                l++;r--;
            }
            l=N/2+1,r=N-1;
            REP(i,N/2-1){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+2==r)break;
                l++;r--;
            }
        }
    }else{
        ll n=(N-1)/2;
        if((N/2)%2==0){
            ll l=0,r=(N/2-1);
            REP(i,n/2+1){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+1==r)break;
                l++;r--;
            }
            l=N/2,r=N-1-1;
            REP(i,n/2){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+2==r)break;
                l++;r--;
            }
        }else{
            ll l=0,r=(N/2-1);
            REP(i,n/2){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+1==r)break;
                l++;r--;
            }
            l=N/2,r=N-1-1;
            REP(i,n/2){
                cout<<l+1<<" "<<r+1<<"\n";cnt++;if(cnt==M)exit(0);
                if(l+2==r)break;
                l++;r--;
            }
        }
    }
}