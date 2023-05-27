#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, s; cin >> n >> s;

  int cnt = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i + j <= s) cnt++;
      else break;
    }
  }

  cout << cnt << "\n";
}