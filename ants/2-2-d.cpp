#include<iostream>
#include<vector>
using namespace std;



int N;
int R;
vector<int> X;

void solve();
int main(){
    cin>>N>>R;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        X.push_back(x);
    }

    solve();
}

int pos;
int i=0;
int ans=0;
void solve(){
    while(i<N){
        pos=X[i];
        while(i<N&&X[i]<=pos+R){
            i++;
        }
        i--;ans++;
        pos=X[i];
        while(i<N&&X[i]<=pos+R){
            i++;
        }
    }
    cout<<ans<<"\n";
}

// 23'05"