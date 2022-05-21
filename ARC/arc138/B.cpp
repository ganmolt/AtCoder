//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
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
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
int main(void){
    Int N;cin>>N;
    deque<int> que;
    REP(i,N){
        int a;cin>>a;
        que.push_back(a);
    }
    int swtch=0;int i=0;
    while(!que.empty()){
        if(i==N){
            cout<<"No\n";
            exit(0);
        }
        auto r=que.back();
        if(r==swtch){
            que.pop_back();
        }else{
            if(que.front()==swtch){
                que.pop_front();
                swtch=1-swtch;
            }
            else{
                cout<<"No\n";
                exit(0);
            }
        }
        i++;
    }
    cout<<"Yes\n";
}

