#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N;
multiset<int> s;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int l;
        cin>>l;
        s.insert(l);
    }
    int ans=0;
    while(s.size()>1){
        auto itr=s.begin();
        int tmp=*itr;s.erase(itr++);
        tmp+=*itr;s.erase(itr);
        ans+=tmp;
        s.insert(tmp);
        for(auto r: s){
            cout<<r<<" ";
        }cout<<" => "<<ans<<"\n";
    }
}