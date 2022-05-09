#include<iostream>
#include<vector>

using namespace std;


int n;
string S;
int main(){
    cin>>n;
    cin>>S;

    string T; string tmp;
    int l=0,r=n-1;
    bool left=true;
    while(l<=r){
        for(int i=0;l+i<r;i++){
            if(S[l+i]<S[r-i]){
                left=true;
                break;
            }
            else if(S[l+i]>S[r-i]){
                left=false;
                break;
            }
        }
        if(left)putchar(S[l++]);
        else putchar(S[r--]);
    }
    cout<<"\n";
}

//27'36"
