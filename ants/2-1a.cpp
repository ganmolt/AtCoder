#include <iostream>
#include <math.h>
int fact(long int);
int main(){
    std::cout<<fact(10)<<"\n";
}
int fact(long int n){
    if(n==0)return 1;
    return n*fact(n-1);
}