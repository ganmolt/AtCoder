#include<bits/stdc++.h>

using namespace std;

#define ALLv(v) v.begin(),v.end()
#define ll long long
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define FOR(i,k,n) for(ll (i)=(k);(i)<(n);(i)++)

int main(){
    vector<ll> v;
    REP(i,6){
        ll x;cin>>x;
        v.push_back(x);
    }
    //REP(i,6)cout<<v[i]<<" ";
    sort(ALLv(v),greater<ll>());
    cout<<v[2]<<"\n";
}