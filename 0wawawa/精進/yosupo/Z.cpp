#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> Zalgo(string str){
    int n=str.size();
    vector<int> a(n,0);
    int from=-1,last=-1;
    for(int i=1;i<n;i++){
        int &same=a[i];
        if(from!=-1){
            same=min(a[i-from],last-i);
            same=max(same,0);
        }
        while(same<n && str[same]==str[i+same])same++;
        if(last<i+same){
            last=i+same;
            from=i;
        }
    }
    a[0]=n;
    return a;
}

int main(){
    string S;
    cin>>S;
    auto a=Zalgo(S);
    for(auto elem:a)cout<<elem<<" ";cout<<"\n";
}