#include <bits/stdc++.h>
typedef long long int Int;

using namespace std;

vector<int> primeFactor(Int n){
    vector<int> ret;
    int sn=sqrt(n);
    for(int i=2;i<=sn;i++){
        while(n%i==0){
            n/=i;
            ret.push_back(i);
        }
    }
    if(n!=1)ret.push_back(n);
    return ret;
}

int main(){
    Int n;cin>>n;
    vector<int> v=primeFactor(n);
    cout<<n<<": ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<(i==v.size()-1?"\n":" ");
    }
}