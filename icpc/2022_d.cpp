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
    vector<int> b(n);REP(i,n)cin>>b[i];
    sort(b.begin(),b.end(),greater<int>());
    int ans=0;

    int a[3];REP(i,3)a[i]=b[i];
    b.erase(b.begin(),b.begin()+3);
    REP(i,b.size()){
        cout<<b[i]<<" ";
    }cout<<"\n";

    sort(b.begin(),b.end());
    REP(i,b.size()){
        cout<<b[i]<<" ";
    }cout<<"\n";

    while(true){
        cout<<"a: ";REP(i,3)cout<<a[i]<<" ";
        int m=min(a[0],min(a[1],a[2]));
        ans+=m;
        REP(i,3)a[i]-=m;
        cout<<"=>";REP(i,3)cout<<a[i]<<" ";cout<<"ans: "<<ans<<" \n";
        
        bool is_0[3];REP(i,3)is_0[i]=false;

        REP(i,3)if(a[i]==0)is_0[i]=true;

        int cnt_0=0;REP(i,3)cnt_0+=is_0[i];
        if(cnt_0==1){
            //a[i=0:3]以下の最大
            REP(i,3){
                if(is_0[i]){
                    if(b.size()==0){
                        cout<<ans<<"\n";
                        exit(0);
                    }
                    int key=max(a[0],max(a[1],a[2]));
                    int idx=upper_bound(b.begin(),b.end(),key)-b.begin();
                    a[i]=b[idx-1];
                    b.erase(b.begin()+idx-1);
                    cout<<"new: "<<a[i]<<" list0: ";REP(i,b.size())cout<<b[i]<<" ";cout<<"\n";
                }
            }
        }else{
            //最大から2つ
            //最大から3つ
            REP(i,3){
                if(is_0[i]){
                    if(b.size()==0){
                        cout<<ans<<"\n";
                        exit(0);
                    }
                    a[i]=*(b.end()-1);
                    b.erase(b.end()-1);
                }
            }
        }
        REP(i,b.size()){
            cout<<b[i]<<" ";
        }cout<<"\n";
    }
}
    /*
    queue<int> que;
    REP(i,n)que.push(b[i]);
    auto r1=que.front();que.pop();
    auto r2=que.front();que.pop();
    auto r3=que.front();que.pop();
    while(!que.empty()){
        
    }*/