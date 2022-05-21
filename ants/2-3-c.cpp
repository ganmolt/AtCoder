#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int n,W;
vector<int> v,w;
int dp[110][11000];

void solve(){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            if(j<w[i])dp[i][j]=dp[i+1][j];
            else dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[0][W]<<"\n";
}
int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        int ww,vv;
        cin>>ww>>vv;
        w.push_back(ww);
        v.push_back(vv);
    }
    solve();
}