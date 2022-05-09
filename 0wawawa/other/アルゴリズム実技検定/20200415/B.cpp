#include<iostream>

using namespace std;

#define ll long long
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define FOR(i,k,n) for(ll (i)=(k);(i)<(n);(i)++)

int main(){
    ll N;cin>>N;
    ll A[N];REP(i,N)cin>>A[i];

    REPS(i,N-1){
        if(A[i-1]==A[i])cout<<"stay";
        else if(A[i-1]>A[i])cout<<"down "<<A[i-1]-A[i];
        else cout<<"up "<<A[i]-A[i-1];
        cout<<"\n";
    }
}