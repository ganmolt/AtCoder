#include<bits/stdc++.h>

using namespace std;

#define Int long long int
Int N,K;
vector<Int> A,B;
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        Int aa;cin>>aa;
        A.push_back(aa);
    }for(int i=0;i<N;i++){
        Int bb;cin>>bb;
        B.push_back(bb);
    }
    set<int> now;
    now.insert(A[0]);
    now.insert(B[0]);
    for(int i=1;true;i++){
        if(i==N){
            cout<<"Yes\n";
            return 0;
        }
        set<int> tmp;
        for(auto r:now){
            if(-K<=A[i]-r&&A[i]-r<=K){
                tmp.insert(A[i]);
            }
            if(-K<=B[i]-r&&B[i]-r<=K){
                tmp.insert(B[i]);
            }
        }
        if(tmp.size()==0){
            cout<<"No\n";
            return 0;
        }
        now=tmp;
    }

}