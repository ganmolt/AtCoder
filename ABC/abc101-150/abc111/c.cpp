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
    int n;cin>>n;
    vector<int> v(n);REP(i,n)cin>>v[i];
    vector<int> a1,a2;
    REP(i,n){
        if(i%2==0){
            a1.push_back(v[i]);
        }
        else{
            a2.push_back(v[i]);
        }
    }
    map<int,int> m1,m2;
    REP(i,a1.size()){
        m1[a1[i]]++;
    }
    REP(i,a2.size()){
        m2[a2[i]]++;
    }
    int mx1=-1,mx2=-1;
    int m1_1=0,m2_1=0,m1_2=0,m2_2=0;
    for(auto r:m1){
        if(chmax(m2_1,r.second)){
            if(m1_1<m2_1){
                m2_1^=m1_1^=m2_1^=m1_1;
                mx1=r.first;
            }
        }
    }
    for(auto r:m2){
        if(chmax(m2_2,r.second)){
            if(m1_2<m2_2){
                m2_2^=m1_2^=m2_2^=m1_2;
                mx2=r.first;
            }
        }
    }
    Int ans;
    if(mx1==mx2){
        //cout<<(a1.size()-m1_1)+(a2.size()-m2_2)<<","<<(a1.size()-m1_2)+(a2.size()-m2_1)<<"\n";
        ans=min(
            (a1.size()-m1_1)+(a2.size()-m2_2),
            (a1.size()-m2_1)+(a2.size()-m1_2)
        );
    }else{
        //cout<<mx1<<","<<mx2<<":"<<m1_2<<"::";
        //cout<<(a1.size()-m1_1)<<" "<<(a2.size()-m1_2)<<"\n";
        ans=(a1.size()-m1_1)+(a2.size()-m1_2);
    }
    cout<<ans<<"\n";
}