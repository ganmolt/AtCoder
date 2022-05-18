#include<bits/stdc++.h>
using namespace std;
#define Int long long int

vector<Int> A;
int main(){
    Int N,K,X;cin>>N>>K>>X;
    int a;
    for(int i=0;i<N;i++){
        cin>>a;
        A.push_back(a);
    }

    for(int i=0;i<N;i++){
        if(K==0)break;
        int max_use_n=A[i]/X;
        if(max_use_n<=K){
            K-=max_use_n;
            A[i]=A[i]%X;
        }else{
            A[i]-=K*X;
            K=0;
        }

    }
    if(K!=0){
        sort(A.begin(),A.end(),greater<Int>());
        for(int i=0;i<N;i++){
            if(K==0)break;
            A[i]=0;
            K--;
        }
    }

    Int sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    cout<<sum<<"\n";
}