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
    string s;cin>>s;
    int l=0,r=0;
    Int c[26];REP(i,26)c[i]=0;
    Int ccnt=0;
    Int n=s.size();
    do{
        if(r<n&&c[s[r]-'a']>=1){
            c[s[r]-'a']++;
            r++;
        }else{//c[idx]==0
            if(r<n&&ccnt<=1){
                ccnt++;
                c[s[r]-'a']++;
                r++;
            }else{
                ccnt--;
                c[s[l]-'a']--;
                l++;
            }
        }
        //cout<<l<<":"<<r<<"\n";
        //REP(i,26)cout<<c[i]<<" ";cout<<"\n";
        Int csm=0;
        REP(i,26)csm+=c[i];
        REP(i,26){
            if(r-l>=2&&csm/2<c[i]){
                cout<<l+1<<" "<<r<<"\n";
                exit(0);
            }
        }
    }while(l<r);
    cout<<"-1 -1\n";
}