#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, s; cin >> n >> s;

  int a[n]; for(int i=0; i < n; i++){
    cin >> a[i];
  }

  int dp[66][11000];
  for(int i = 0; i < 66; i++){
    for(int j = 0; j < 11000; j++){
       dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= s; j++){
      if(dp[i][j] <= 0) continue;
      //erabu
      if(j+a[i] <= 10000){
        dp[i+1][j+a[i]] += dp[i][j];
      }
      //erabanai
      dp[i+1][j] += dp[i][j];
    }
  }

  int ans = 0;
  for(int j = 0; j <= s; j++){
    ans = max(ans, dp[n][s]);
  }

  if( ans > 0 ){
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }
}