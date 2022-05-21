#include<bits/stdc++.h>
using namespace std;
#define Int long long int

int n,W;
vector<int> v,w;
int dp[110][11000];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][W]<<"\n";
}

int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        int vv,ww;
        cin>>ww>>vv;
        v.push_back(vv);
        w.push_back(ww);
    }

    solve();
}