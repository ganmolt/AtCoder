#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
 
int main(){
    int n;cin >> n;
    vector<int> c(n),cnt(n,0);
    for(int i=0;i<n;i++){
        cin>>c[i];
        c[i]--;
    }
    int count=0, now_l=0, now_r=0;
    
    int q;cin>>q; int sq=sqrt(q);
    vector<int> l(q),r(q),X(q),idx(q),ans(q);
    for (int i=0;i<q;i++) {
        cin>>l[i]>>r[i]>>X[i];l[i]--;X[i]--;
    }
    iota(idx.begin(), idx.end(),0);
    sort(idx.begin(), idx.end(), [&](int a,int b){
        if (l[a]/sq!=l[b]/sq) return l[a]<l[b];
        if (l[a]/sq%2==1) return r[a]>r[b];
        return r[a]<r[b];
    });
    auto add = [&](int x) {
        if (cnt[c[x]]==0) count++;
        cnt[c[x]]++;
    };
    auto del = [&](int x) {
        cnt[c[x]]--;
        if (cnt[c[x]]==0) count--;
    };
    for (int i=0;i<q;i++) {
        while(now_l > l[idx[i]]) add(--now_l);
        while(now_r < r[idx[i]]) add(now_r++);
        while(now_l < l[idx[i]]) del(now_l++);
        while(now_r > r[idx[i]]) del(--now_r);
        ans[idx[i]] = count;
        ans[idx[i]]=cnt[X[idx[i]]];
    }
    for (int i=0;i<q;i++) cout<<ans[i]<<"\n";
    return 0;
}