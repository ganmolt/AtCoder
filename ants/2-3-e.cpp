#include<bits/stdc++.h>
using namespace std;

int n,W;
int dp[110][11000];
vector<int> v,w;

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j+w[i]<=W){
                dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
            }
        }
    }
    cout<<dp[n][W]<<"\n";
}

int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        int ww,vv;
        cin>>ww>>vv;
        v.push_back(vv);
        w.push_back(ww);
    }
    solve();
}