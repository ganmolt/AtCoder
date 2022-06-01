//Range Sum Query

#include <bits/stdc++.h>
using namespace std;
#define Int long long int
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)

// 1-idx
template <typename T>
struct BIT{
    int n;
    vector<T> bit[2];
    BIT(int n_) { init(n_); }
    void init(int n_){
        n=n_+1;
        for(int p=0;p<2;p++)bit[p].assign(n,0);
    }

    void add_sub(int p, int i, T x){
        for(int idx=i;idx<n;idx+=(idx&-idx)){
            bit[p][idx]+=x;
        }
    }
    void add(int l, int r, T x){
        add_sub(0, l, -x*(l-1));
        add_sub(0, r, x*(r-1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i){
        T s(0);
        for(int idx=i;idx>0;idx-=(idx&-idx)){
            s+=bit[p][idx];
        }
        return s;
    }
    T sum(int i){ return sum_sub(0,i)+sum_sub(1,i)*i; }

    // [l,r)の区間和を取得
    T query(int l, int r){ return sum(r-1)-sum(l-1); }
};

int main(){
    int n,q;cin>>n>>q;
    vector<int> c(q),x(q),y(q);
    REP(i,q)cin>>c[i]>>x[i]>>y[i];

    BIT<int> bt(n);

    REP(i,q){
        if(c[i]==0){
            bt.add(x[i],x[i]+1,y[i]);
        }else{
            cout<<bt.query(x[i],y[i]+1)<<"\n";
        }
    }
}