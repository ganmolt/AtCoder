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
struct c{
    int m=1e9;
    int cnt=0;
};

int main(void){
    int n,k;cin>>n>>k;
    vector<int> p(n);REP(i,n)cin>>p[i];

    set<c, function<bool(c,c)>> s{
        [](c a,c b){
            return a.m<b.m;
        }
    };
    vector<int> ans(n+1,-1);
    
    vector<int> under(220000,-1);
    
    REP(i,n){
        
        c r;
        auto it=s.lower_bound({p[i],0});
        if(it!=s.end()){
            //cout<<"FIND";
            //ok
            r=*it;
            s.erase(it);
            //cout<<r.m<<", "<<r.cnt<<": ";
            
        }
        
        if(r.m<p[i]){
            s.insert(r);
            c r2;
            if(r2.m>p[i]){
                under[p[i]]=r2.m;
                r2.m=p[i];
            }
            r2.cnt++;
            //cout<<"NEW: "<<r2.m<<", "<<r2.cnt<<": ";
            if(r2.cnt==k){
                int x=r2.m;
                while(x!=-1){
                    ans[x]=i+1;
                    x=under[x];
                }
            }else{
                s.insert(r2);
            }

            continue;
        }
        
        if(r.m>p[i]){
            under[p[i]]=r.m;
            r.m=p[i];
        }
        
        r.cnt++;

        //cout<<r.m<<", "<<r.cnt<<": ";
        if(r.cnt==k){
            
            //cout<<"erase\n";
            int x=r.m;
            //cout<<x<<"=>"<<under[x]<<"\n";
            //while(x!=-1){
            REP(j,k){
                //cout<<x<<"=>";
                ans[x]=i+1;
                x=under[x];
            }
        }else{
            s.insert(r);
        }
    }
    FOR(i,1,n+1){
        cout<<ans[i]<<"\n";
    }
}