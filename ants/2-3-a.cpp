#include<iostream>
#include<vector>
using namespace std;

int n,W;
vector<int> w,v;
int rec(int,int);
void solve();
int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        int vv,ww;
        cin>>ww>>vv;
        w.push_back(ww);
        v.push_back(vv);
    }
    solve();
}
void solve(){
    cout<<rec(0,W)<<"\n";
}
int rec(int i,int j){
    int res=0;
    if(i==n){//おわり
        res=0;
    }else if(j<w[i]){
        res=rec(i+1,j);
    }
    else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }
    return res;
}