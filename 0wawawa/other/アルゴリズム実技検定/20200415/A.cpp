#include<iostream>
#include<string>
using namespace std;
int main(){
    string S;cin>>S;
    int M=0;bool f=true;
    for(auto r:S){
        if('0'<=r&&r<='9')M=M*10+r-'0';
        else{
            f=false;break;
        }
    }
    if(f)cout<<M*2<<"\n";
    else cout<<"error\n";
}