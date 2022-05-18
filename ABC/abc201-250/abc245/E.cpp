#include<bits/stdc++.h>
using namespace std;

#define Int long long int

Int N,M;

vector<Int> A,B;
vector<Int> C,D;

struct P{
    Int first,second;
    char C;
};

bool operator<(const P& l,const P& r){
    if(l.first==r.first)return l.C<r.C;
    return l.first<r.first;
}
bool operator>(const P& l,const P& r){
    if(l.first==r.first)return l.C<r.C;
    return l.first>r.first;
}


multiset<P,greater<P>> ms;
multiset<Int> S;

int main(){
    cin>>N>>M;
    Int tmp;
    for(int i=0;i<N;i++){cin>>tmp; A.push_back(tmp);}
    for(int i=0;i<N;i++){cin>>tmp; B.push_back(tmp);}
    for(int i=0;i<M;i++){cin>>tmp; C.push_back(tmp);}
    for(int i=0;i<M;i++){cin>>tmp; D.push_back(tmp);}

    for(int i=0;i<N;i++){
        P p={A[i],B[i],'C'};
        ms.insert(p);
    }
    for(int i=0;i<M;i++){
        P p{C[i],D[i],'B'};
        ms.insert(p);
    }

    for(auto r=ms.begin();true;r++){
        if(r==ms.end()){
            cout<<"Yes\n";
            return 0;
        }
        if(r->C=='B'){
            S.insert(r->second);
        }else if(r->C=='C'){
            auto itr=S.lower_bound(r->second);
            if(itr==S.end()){
                cout<<"No\n";
                return 0;
            }else{
                S.erase(itr);
            }
        }
        //cout<<":::A: "<<(c==Ch.end())<<"&"<<" B: "<<(b==Bx.end())<<"\n";

        //for(auto r2:Ch)cout<<r2.first<<","<<r2.second<<" ";cout<<"\n";
        //for(auto r1:Bx)cout<<r1.first<<","<<r1.second<<" ";cout<<"\n";
        
    }
}

//