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
    Int n;cin>>n;
    vector<int> c1(n),c2(n);REP(i,n)cin>>c1[i]>>c2[i];
    vector<int> p[n];REP(i,n){
        p[i].push_back(c1[i]);
        p[i].push_back(c2[i]);
    }
    REP(i,n){
        sort(p[i].begin(),p[i].end());
    }

    auto print = [&]() {
        cout<<"CARDS:\n";
        REP(i,n){
            cout<<i<<": ";
            REP(k,p[i].size())cout<<p[i][k]<<" ";
            cout<<"\n";
        }
    };
    /*
    cout<<"CARDS:\n";
    REP(i,n){
        REP(k,2)cout<<p[i][k]<<" ";
        cout<<"\n";
    }*/

    int i=0,cnt=0;
    while(cnt<n){
        REP(j,p[i].size()-1){
            cout<<i<<","<<j<<"?";
            cout<<p[i][j]<<","<<p[i][j+1]<<"\n";
            if(p[i][j]==p[i][j+1]){
                cout<<i<<":::";
                p[i].erase(p[i].begin()+j,p[i].begin()+j+2);
                //cout<<p[i].size()<<"\n";
                //p[i].erase(p[i].begin()+j);
                //p[i].erase(p[i].begin()+j);
                cout<<p[i].size()<<"\n";
                break;
            }
        }
        if(p[i].size()==0){
            cnt++;
            i=(cnt)%n;
            continue;
        }
        p[i+1].push_back(p[i][0]);
        p[i].erase(p[i].begin());


        print();
        //p[i][0]
        cnt++;
        i=(cnt)%n;
    }
    
}