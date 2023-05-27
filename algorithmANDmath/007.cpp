#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
  return a%b == 0 ? b : gcd(b, a%b);
}

int lcm(int a,int b){
  return a * b / gcd(a,b);
}

int main(){
  int n,x,y; cin >> n >> x >> y;

  int ans1 = 0;
  for(int i = 1; i <= n; i++){
    if(i%x == 0 || i%y == 0) ans1++;
  }

  int ans2 = 0;
  for(int i = 1; i <=n; i++){
    if(i%x == 0) ans2++;
    if(i%y == 0) ans2++;
    if(i%(lcm(x,y)) == 0) ans2--;
  }

  int ans3 = 0;
  ans3 = n/x + n/y - n/lcm(x,y);
  
  // printf("%d, %d, %d\n", ans1, ans2, ans3);
  cout << ans3 << "\n";
}