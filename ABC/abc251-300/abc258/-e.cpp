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
bool isFinished[220000];
int main(void){
    Int n,q,x;cin>>n>>q>>x;
    vector<Int> w(n);REP(i,n)cin>>w[i];
    vector<Int> k(q);REP(i,q)cin>>k[i];

    vector<int> a0;
    int i=0;
    Int tmp=0,cnt=0;
    while(true){
        if(i==n){
            i=0;
        }
        tmp+=w[i];
        cnt++;
        if(tmp>=x){
            a0.push_back(cnt);
            tmp=0;cnt=0;
            if(isFinished[i]){
                break;
            }
            isFinished[i]=true;
        }
        i++;
    }

    vector<Int> a;
    Int tmp2=0,cnt2=0;
    for(int j=(i+1)%n;;j++){
        if(j>=n)j=0;
        //cout<<j<<"=>";
        tmp2+=w[j];
        cnt2++;
        if(tmp2>=x){
            a.push_back(cnt2);
            tmp2=0;cnt2=0;
            if(j==i)break;
        }
    }//cout<<"\n";
    //for(auto r:a0)cout<<r<<" ";cout<<"\n";
    //for(auto r:a)cout<<r<<" ";cout<<"\n";
    REP(j,q){
        Int ans;
        if(k[j]<=a0.size()){
            ans=a0[k[j]-1];
        }else{
            k[j]-=a0.size();
            ans=a[k[j]%a.size()-1];
        }
        cout<<ans<<"\n";
    }
}