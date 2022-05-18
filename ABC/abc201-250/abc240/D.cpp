#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> a;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int aa;cin>>aa;
        a.push_back(aa);
    }
    typedef pair<int,int> P;
    stack<P> ans;
    int count=0;
    for(int i=0;i<N;i++){
        if(ans.empty()){
            ans.push(make_pair(a[i],1));
            count++;
            cout<<count<<"\n";
            continue;
        }
        if(ans.top().first==a[i]){
            ans.top().second++;
            count++;
            if(ans.top().second==ans.top().first){
                count-=ans.top().second;
                ans.pop();
            }
        }else{
            ans.push(make_pair(a[i],1));
            count++;
        }
        cout<<count<<"\n";

    }
}