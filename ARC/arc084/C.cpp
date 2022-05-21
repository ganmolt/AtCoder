#include<bits/stdc++.h>
#define Int long long int
using namespace std;

int N;
vector<Int> A,B,C;
int main(){
    cin>>N;
    Int tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        A.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        cin>>tmp;
        B.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        cin>>tmp;
        C.push_back(tmp);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    vector<Int> Bcnt(N);
    for(int i=0;i<N;i++){
        auto it=upper_bound(C.begin(),C.end(), B[i]);
        Bcnt[i]=C.end()-it;
    }

    for(int i=N-1;i>0;i--){
        Bcnt[i-1]+=Bcnt[i];
    }

    Int ans=0;
    for(int i=0;i<N;i++){
        auto it=upper_bound(B.begin(),B.end(),A[i]);
        Int idx=it-B.begin();
        ans+=Bcnt[idx];
    }
    cout<<ans<<"\n";

}