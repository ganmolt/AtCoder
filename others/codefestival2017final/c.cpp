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
    vector<int> d(n);REP(i,n)cin>>d[i];

    if(n>25){
        cout<<"0\n";
        exit(0);
    }
    map<int,int> m;
    REP(i,n)m[d[i]]++;

    vector<int> v0;v0.push_back(0);
    vector<int> com;
    for(int i=0;i<=12;i++){
        // 0
        if(i==0){
            if(m[i]==0)continue;
            if(m[i]>0){
                cout<<"0\n";
                exit(0);
            }
            continue;
        }
        // 12
        if(i==12){
            if(m[i]==1){
                v0.push_back(i);
            }
            if(m[i]>1){
                cout<<"0\n";
                exit(0);
            }
            continue;
        }
        // 1-11
        if(m[i]==1){   
            com.push_back(i);
        }
        if(m[i]==2){
            v0.push_back(i);
            v0.push_back(24-i);
        }
        if(m[i]>2){
            cout<<"0\n";
            exit(0);
        }
    }
    //cout<<"v0: ";
    //for(auto r:v0)cout<<r<<" ";cout<<"\n";




    int ans=0;
    for(int bit=0;bit<(1<<com.size());bit++){
        vector<int> v(v0);
        for(int i=0;i<com.size();i++){
            if(bit&(1<<i)){
                v.push_back(com[i]);
            }else{
                v.push_back(24-com[i]);
            }
        }
        sort(v.begin(),v.end());
        int m=1e9;
        //cout<<"v: ";REP(i,v.size())cout<<v[i]<<" ";cout<<"\n";
        REP(i,v.size()){
            if(i==(v.size()-1)){
                //cout<<"last: "<<v[i]<<", "<<24-v[i]<<"\n";
                chmin( m,min(v[i], 24-v[i]) );
                continue;
            }
            chmin(m,min( v[i+1]-v[i], 24-(v[i+1]-v[i]) ));
        }

        chmax(ans,m);
    }
    cout<<ans<<"\n";
}