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
    int q;cin>>q;
    vector<Int> c(q),x(q),k(q);
    REP(i,q){
        cin>>c[i]>>x[i];
        if(c[i]>=2){
            cin>>k[i];
        }
    }

    multiset<Int> s;
    REP(i,q){
        //cout<<i<<": ";for(auto r:s)cout<<r<<" ";cout<<"\n";
        if(c[i]==1){
            s.insert(x[i]);
        }
        if(c[i]==2){
            if(s.size()==0){
                cout<<-1<<"\n";
                continue;
            }
            auto it=s.upper_bound(x[i]);
            //cout<<(*it)<<"以下の大きいほうから"<<k[i]<<": ";
            bool f=false;
            while(k[i]-->0){
                if(it--==s.begin()){
                    cout<<-1<<"\n";
                    f=true;
                    break;
                }
            }
            if(!f)cout<<*it<<"\n";
        }
        if(c[i]==3){
            if(s.size()==0){
                cout<<-1<<"\n";
                continue;
            }
            auto it=s.lower_bound(x[i]);
            if(it==s.end()){
                cout<<-1<<"\n";
                continue;
            }
            //cout<<(*it)<<"以上の小さいほうから"<<k[i]<<": ";
            bool f=false;
            while(k[i]-->1){
                if(++it==s.end()){
                    cout<<-1<<"\n";
                    f=true;
                    break;
                }
            }
            if(!f)cout<<*it<<"\n";
        }
    }
}