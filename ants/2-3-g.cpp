#include<bits/stdc++.h>

using namespace std;

int n,W;
vector<int> w,v;
int dp[110][11000];
int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        int ww,vv;
        cin>>ww>>vv;
        w.push_back(ww);
        v.push_back(vv);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])dp[i+1][j]=dp[i][j];
            else{
                dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][W]<<"\n";
}