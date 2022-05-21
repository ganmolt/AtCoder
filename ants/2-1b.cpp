#include <iostream>
using namespace std;
int fib(int);
int main(){
    for(int i=900;i<=1000;i++){
        cout<<i<<":"<<fib(i)<<"\n";
    }
}

int fib(int n){
    if(n==1)return 1;
    if(n==0)return 0;
    return fib(n-1)+fib(n-2);
}
