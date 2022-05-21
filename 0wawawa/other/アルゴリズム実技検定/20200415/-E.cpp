#include<bits/stdc++.h>

using namespace std;

#define ALLv(v) v.begin(),v.end()
#define ll long long
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define FOR(i,k,n) for(ll (i)=(k);(i)<(n);(i)++)


vector<ll> FL[101];
vector<ll> FW[101];
int main(){
    ll N,Q;cin>>N;cin>>Q;
    ll q,a,b;
    REP(i,Q){
        cin>>q;
        switch(q){
            case 1:
                cin>>a>>b;
                FL[a].push_back(b);
                FW[b].push_back(a);
            break;
            case 2:
                cin>>a;
                for(auto r:FW[a]){
                    FL[a].push_back(r);
                    FW[r].push_back(a);
                }
            break;
            case 3:
                cin>>a;
                vector<ll> qA=FL[a];
                for(auto r:qA){
                    for(auto u:FL[r]){
                        FL[a].push_back(u);
                        FW[u].push_back(a);
                    }
                }
            break;
        }
    }
    bool f[N+1][N+1];REPS(i,N)REPS(j,N)f[i][j]=false;
    REPS(i,N){
        for(auto r:FL[i]){
            f[i][r]=true;
        }
    }
    REPS(i,N){
        REPS(j,N)cout<<(f[i][j]?'Y':'N');
        cout<<"\n";
    }
}