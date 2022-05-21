#include<bits/stdc++.h>

using namespace std;

#define ALLv(v) v.begin(),v.end()
#define ll long long
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define FOR(i,k,n) for(ll (i)=(k);(i)<(n);(i)++)

ll cnt[200000];
int main(){
    ll N;cin>>N;
    REP(i,N){
        ll x;cin>>x;
        cnt[x]++;
    }
    ll ans1=-1,ans2=-1;
    REPS(i,N){
        if(cnt[i]>=2)ans1=i;
        if(cnt[i]<1)ans2=i;
    }
    if(ans1==-1&&ans2==-1)cout<<"Correct";
    else cout<<ans1<<" "<<ans2;
    cout<<"\n";
}