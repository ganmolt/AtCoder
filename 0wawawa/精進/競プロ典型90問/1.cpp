#include<iostream>
#include<vector>

using namespace std;
using Int=long long;

Int N,L,K;
Int solve(Int X, vector<Int> A){
    Int m=1000000000+9;
    Int l=0,cutCnt=0;
    Int z=0;
    for(Int i=0;i<N;i++){
        if(cutCnt>=K)break;
        l+=A[i]-z;
        if(l>=X){
            m=min(l,m);
            cutCnt++;
            l=0;
        }
        z=A[i];
    }
    if(L-z>=X) m=min(L-z,m);
    else m=-1;
    if(cutCnt>=K)return m;
    return -1;
}

int main(){
    cin>>N>>L>>K;
    vector<Int> A(N);
    for(Int i=0;i<N;i++)cin>>A[i];

    Int ans=-999;
    Int lb=0;Int ng=1e9+1;
    while(true){
        if(ng-lb<=1)break;
        Int X=(lb+ng)/2;
        Int s=solve(X,A);
        if(s==-1)ng=X;
        else{
            lb=X;
            ans=max(ans,solve(X,A));
        }
    }
    
    cout<<ans<<"\n";
}