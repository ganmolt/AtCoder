#include<iostream>
#include<vector>

using namespace std;
const int value[6]={1,5,10,50,100,500};
vector<int> C(6);
int A;
void solve();
int main(){
    cin>>A;
    for(int i=0;i<6;i++){
        cin>>C[i];
    }

    solve();
}
void solve(){
    int ans=0;
    for(int i=5;i>=0;i--){
        int max_use=A/value[i];
        int use=min(max_use,C[i]);
        A-=value[i]*use;
        ans+=use;
    }
    cout<<ans<<"\n";
}