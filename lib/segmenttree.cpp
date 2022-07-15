#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define INF __LONG_LONG_MAX__
#define inf __INT_MAX__
//RMQ
//1-ind
struct SegmentTree{
private:
    int n;
    vector<Int> dat;
public:
    SegmentTree(vector<Int> v){
        int sz=v.size();
        n=1;while(n<sz)n*=2;
        dat.resize(2*n,INF);

        for(int i=0;i<sz;i++){
            dat[n+i]=v[i];
        }
        for(int i=n-1;i>=1;i--){
            dat[i]=min(dat[i*2],dat[i*2+1]);
        }
    }
    void update(int i, int x){
        i+=n;
        dat[i]=x;
        //cout<<i<<":"<<dat[i]<<"\n";
        while(i>0){
            i=i/2;
            dat[i]=min(dat[i*2],dat[i*2+1]);
        }
    }
    Int getmin(int a, int b, int i=1, int l=0, int r=-1){
        if(r<0)r=n;
        //cout<<a<<" "<<b<<" "<<i<<" "<<l<<" "<<r<<" \n";
        if(r<=a || b<=l){
            //cout<<"retInf\n";
            return INF;
        }
        //求めたい区間a,bがそこの担当領域l,rを完全に含んでいれば
        if(a<=l && r<=b){
            //cout<<"ret:"<<dat[i]<<"\n";
            return dat[i];

        }
        //でなければ、子を用意する
        Int ll=getmin(a,b,i*2,l,(l+r)/2);
        Int rr=getmin(a,b,i*2+1,(l+r)/2,r);
        return min(ll,rr);

    }

    void out(){
        int k=1;
        for(int i=1;i<2*n;i++){
            cout<<dat[i];
            if(i==k){
                cout<<"\n";
                k=k*2+1;
            }
            else cout<<" ";
        }
    }

};

int main(){
    int N;cin>>N;
    vector<Int> v(N);
    for(int i=0;i<N;i++)cin>>v[i];
    SegmentTree T(v);
    int Q;cin>>Q;
    for(int i=0;i<Q;i++){
        int q;cin>>q;
        if(q==0){
            int j,x;cin>>j>>x;
            T.update(j,x);
        }else if(q==1){
            int a,b;cin>>a>>b;
            cout<<T.getmin(a,b)<<"\n";
        }else if(q==2){
            T.out();
        }
    }

    //cout<<INF<<"\n";
    //cout<<inf<<"\n";
}
