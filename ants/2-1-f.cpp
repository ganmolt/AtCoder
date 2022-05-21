#include<iostream>
using namespace std;
/*
n=4
a={1,2,4,7}
k=13
*/
void solve();
bool dfs(int,int);

int a[110000];
int n,k;

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    solve();
}
bool dfs(int i, int sum){
    if(i==n) return sum==k;

    if(dfs(i+1,sum))return true;
    if(dfs(i+1,sum+a[i]))return true;

    return false;
}

void solve(){
    if(dfs(0,0)) cout<<"Yes\n";
    else cout<<"No\n";
}