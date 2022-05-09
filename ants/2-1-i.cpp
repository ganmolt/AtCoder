#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<bool> used;
vector<int> perm;
vector<int> perm2;
int N;
void permutation1(int,int);
void permutation2(int);
int main(){
    cin>>N;
    used.assign(N,0);
    perm.assign(N,0);
    perm2.assign(N,0);
    //permutation1(0,N);
    permutation2(N);
}
void permutation1(int pos, int n){
    if(pos==n){
        return;
    }

    for(int i=0;i<n;i++){
        if(!used[i]){
            perm[pos]=i;
            used[i]=true;
            permutation1(pos+1,n);
            used[i]=false;
        }
    }
    for(int i=0;i<N;i++){
        cout<<perm[i]<<" ";
    }cout<<"\n";
    return;
}


void permutation2(int n){
    for(int i=0;i<n;i++){
        perm2[i]=i;
    }
    do{
        for(int i=0;i<n;i++){
            cout<<perm2[i];
        }cout<<"\n";
    }while(next_permutation(perm2.begin(),perm2.end()));
    return;
}