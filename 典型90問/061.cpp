#include<bits/stdc++.h>
using namespace std;
#define Int long long int
#define REP(i,n) for(Int i = 0; i < n; i++)


int main(){
    deque<Int> deq;

    int Q; cin >> Q;
    Int a[Q], b[Q];
    REP(i,Q){
        cin >> a[i] >> b[i];
    }
    REP(i,Q){
        if(a[i] == 1){
            deq.push_front(b[i]);
        }else if(a[i] == 2){
            deq.push_back(b[i]);
        }else {
            cout << deq[b[i]-1] << "\n";
        }
    }
}
