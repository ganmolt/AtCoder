#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)

int main(){
    int N, Q; cin >> N >> Q;
    Int a[N], b[N-1], v[Q], l[Q], r[Q];
    REP(i, N) cin >> a[i];

    REP(i, Q){
        cin >> l[i] >> r[i] >> v[i];
        l[i]--, r[i]--;
    }

    // あらかじめ不便さを計算
    Int sm = 0;
    REP(i, N-1){
        b[i] = a[i+1] - a[i];
        sm += abs(b[i]);
    }

    REP(i, Q){
        Int ans1 = abs(b[l[i]-1]) + abs(b[r[i]]);
        if(l[i] > 0) b[l[i]-1] += v[i];
        if(r[i] < N-1) b[r[i]] -= v[i];
        Int ans2 = abs(b[l[i]-1]) + abs(b[r[i]]);

        sm += (ans2 - ans1);
        cout << sm << "\n";
    }
    
}
