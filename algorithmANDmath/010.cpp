#include<bits/stdc++.h>

using namespace std;

long long fact(long long n){
  if(n == 0) return 1;
  return n * fact(n-1);
}
int main(){
  int n; cin >> n;
  cout << fact(n) << "\n";
}