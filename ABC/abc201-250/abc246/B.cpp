#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define Double long double
int main(){
    Int A,B;cin>>A>>B;
    Double d=sqrt(A*A+B*B);
    Double a,b;
    a=A/d,b=B/d;
    cout<<setprecision(10)<<a<<" "<<b<<"\n";
}