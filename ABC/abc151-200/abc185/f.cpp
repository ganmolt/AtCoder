//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const Int INF=1010000000000000017LL;
const Int MOD=1000000007LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
class SegmentTree{
public:
    Int inf=INF;
    int n;
    vector<Int> val;

    SegmentTree(int n_){
        int x=1;
        while(n_>x){
            x*=2;
        }
        n=x;
        val=vector<Int>(n*2,0LL);
    }
    void update(int i, Int x){
        i+=n-1;
        val[i]=x;
        while(i>0){
            i=(i-1)/2;
            val[i]=val[i*2+1]^val[i*2+2];
        }
    }
    Int get(int x){
        return val[x+n-1];
    }
    Int query(int a, int b) { return query_sub(a, b, 0, 0, n);cout<<"\n"; }
    Int query_sub(int a,int b,int k,int l,int r){
        //cout<<l<<"-"<<r<<"";
        if(r<=a||b<=l){
            //cout<<"nouse,";
            return 0;
        }
        else if(a<=l&&r<=b){
            //cout<<"use,";
            return val[k];
        }else{
            //cout<<"->";
            Int vl=query_sub(a,b,k*2+1,l,(l+r)/2);
            Int vr=query_sub(a,b,k*2+2,(l+r)/2,r);
            return vl^vr;
        }

    }
    inline Int operator[](int a) { return query(a, a + 1); }
    void print() {
        //cout<<"Print\n";
        int k=2;
        for (int i = 0; i < 2 * n - 1; ++i) {
            //cout << val[i] << " ";
            if(i+1==k-1)/*cout<<"\n",*/k*=2;
        }
        //cout << endl;
    }
};
//-----------------------------------------
int main(void){
    int n,q;cin>>n>>q;
    vector<int> a(n);REP(i,n)cin>>a[i];
    vector<int> t(q),x(q),y(q);REP(i,q)cin>>t[i]>>x[i]>>y[i];


    SegmentTree st(n);
    for(int i=0;i<n;i++)st.update(i,a[i]);
    //st.print();
    REP(i,q){
        //cout<<"i="<<i<<": "<<t[i]<<","<<x[i]-1<<","<<y[i]<<"\n";
        if(t[i]==1){
            x[i]--;
            //st.print();
            //cout<<st.get(x[i])<<"to"<<y[i]<<"\n";
            st.update(x[i],st.get(x[i])^y[i]);
            //st.print();
        }else{
            x[i]--;
            //st.print();
            cout<<st.query(x[i],y[i])<<"\n";
        }
    }
    //cout<<"*::"<<st.n<<","<<st.val.size()<<"\n";
    //st.print();
}