#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


int n;
typedef pair<int,int> P;
vector<P> v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int ss,tt;
        cin>>ss>>tt;
        v.push_back({tt,ss});//終了時間,開始時間
    }
    

    
    sort(v.begin(),v.end());//終了が早いものから見る 
    int nowtime=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(nowtime<v[i].second){
            nowtime=v[i].first;
            ans++;
        }
    }
    cout<<ans<<"\n";
}

