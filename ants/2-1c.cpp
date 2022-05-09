#include <iostream>
using namespace std;
long long int FIB[110000];
long long int fib(int);
int main(){
    for(int i=0;i<110000;i++)FIB[i]=-1;
    for(int i=0;i<=300;i++){
        cout<<i<<":"<<fib(i)<<"\n";
    }
}

long long int fib(int n){
    if(FIB[n]!=-1)return FIB[n];

    if(n==1)return FIB[n]=1;
    if(n==0)return FIB[n]=0;
    return FIB[n]=fib(n-1)+fib(n-2);
}