#include <bits/stdc++.h>
typedef long long int Int;

using namespace std;

Int pow(Int x, Int n, Int mod=1e9+7){
    Int ret=1;
    while(n>0){
        if(n&1)ret=ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}

int main(){
    int m,n;cin>>m>>n;
    cout<<pow(m,n,1e9+7)<<"\n";
}