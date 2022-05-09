#include<iostream>
#include<vector>
#include<utility>
#include<string.h>

using namespace std;

int n;int W;
int dp[110][11000];
vector<int> w,v;



int rec(int i,int j){
    if(dp[i][j]>=0) return dp[i][j];

    if(i==n) return dp[i][j]=0;
    else if(j<w[i]){
        return dp[i][j]=rec(i+1,j);
    }else{
        return dp[i][j]=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<"\n";
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

