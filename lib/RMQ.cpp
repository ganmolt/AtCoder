#include<bits/stdc++.h>
using namespace std;
#define Int long long int
const Int INF = __LONG_LONG_MAX__;
const int inf = __INT_MAX__;
//RMQ
//1-ind
class RMQ{
public:
    Int inf=(1LL<<31)-1;
    int n;
    vector<Int> val;
 
    RMQ(int n_){
        int x=1;
        while(n_>x){
            x*=2;
        }
        n=x;
        val=vector<Int>(n*2,inf);
    }
    void update(int i, Int x){
        i+=n-1;
        val[i]=x;
        while(i>0){
            i=(i-1)/2;
            val[i]=min(val[i*2+1],val[i*2+2]);
        }
    }
    Int get(int x){
        return val[x+n-1];
    }
    Int query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    Int query_sub(int a,int b,int k,int l,int r){
        //cout<<l<<"-"<<r<<"";
        if(r<=a||b<=l){
            //cout<<"nouse,";
            return inf;
        }
        else if(a<=l&&r<=b){
            //cout<<"use,";
            return val[k];
        }else{
            //cout<<"->";
            Int vl=query_sub(a,b,k*2+1,l,(l+r)/2);
            Int vr=query_sub(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
 
    }
    inline Int operator[](int a) { return query(a, a + 1); }
    void print() {
        cout<<"Print\n";
        int k=2;
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << val[i] << " ";
            if(i+1==k-1)cout<<"\n",k*=2;
        }
        cout << endl;
    }
};

int main(){
    int n,q;cin>>n>>q;
    vector<Int> c(q),x(q),y(q);
    for(int i=0;i<q;i++)cin>>c[i]>>x[i]>>y[i];

    RMQ rmq(n);
    for(int i=0;i<q;i++){
        //rmq.print();
        if(c[i]==0){
            rmq.update(x[i],y[i]);
        }
        if(c[i]==1){
            cout<<rmq.query(x[i],y[i]+1)<<"\n";
        }
    }
}
