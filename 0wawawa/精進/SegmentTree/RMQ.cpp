#include<iostream>
using namespace std;

typedef long long ll;

ll INF=(1LL<<31)-1;
ll seg[1LL<<20];
void update(ll pos,ll val){
    pos+=1LL<<19;
    seg[pos]=val;
    while((pos/=2)>0){
        seg[pos]=min(seg[pos*2],seg[pos*2+1]);
    }
}
ll find(ll ql, ll qr, ll sl=0, ll sr=1LL<<19, ll pos=1){
    if(qr<=sl||sr<=ql)return INF;
    if(ql<=sl&&sr<=qr)return seg[pos];
    ll sm=(sl+sr)/2;
    ll lmin=find(ql,qr,sl,sm,pos*2);
    ll rmin=find(ql,qr,sm,sr,pos*2+1);
    return min(lmin,rmin);
}

int main(){
    ll N,Q;cin>>N>>Q;
    ll com,x,y;
    for(ll i=0;i<N;i++)update(i,INF);
    for(ll i=0;i<Q;i++){
        cin>>com>>x>>y;
        if(com==0){//update
            update(x,y);
        }else{//find
            ll m=find(x,y+1);
            cout<<m<<"\n";
        }
    }
}