#include<bits/stdc++.h>
using namespace std;
#define Int long long int


Int N,M;
vector<vector<Int>> G(220000);

int res[220000];
bool gone[220000];
bool dfs(int i){
    if(res[i]>=0)return res[i];
    if(gone[i]==true)return res[i]=true;
    
    gone[i]=true;
    bool ret=false;
    for(auto r:G[i]){
        res[r]=dfs(r);
        gone[r]=false;
        if(res[r])ret=true;
    }
    return res[i]=ret;
}
void solve(){
    Int ans=0;
    for(int i=0;i<N;i++){
        if(dfs(i))ans++;
        gone[i]=false;
    }
    cout<<ans<<"\n";
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        Int f,t;
        cin>>f>>t;f--,t--;
        G[f].push_back(t);
    }
    memset(res,-1,sizeof(res));
    memset(gone,false,sizeof(gone));
    solve();
}

/*//cout<<i<<": ";
        for(auto r:G[i]){
            //cout<<r<<",";
        }//cout<<"\n";
        */