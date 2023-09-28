#include<bits/stdc++.h>
#define Int long long int

using namespace std;

Int count(int x){
    int ret = 0;
    while(x > 0){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main(){

    Int n; cin >> n;
    Int k; cin >> k;

    if(k <= 100000){
        for(int i = 0; i < k; i++){
            Int c = count(n);
            n += c;
            n %= 100000;
        }
        cout << n << "\n";
        return 0;
    }


    int mi[100000];
    for(int i = 0; i < 100000; i++){
        mi[i] = -1;
    }

    Int p; Int s;
    for(Int i = 0; i <= 100000; i++){
        Int c = count(n);
        n += c;
        n %= 100000;

        if(mi[n] == -1){
            mi[n] = i;
        }else{
            p = i - mi[n];
            s = mi[n];
            break;
        }
    }
    // cout << "p: " << p << "\n";
    // cout << "s: " << s << "\n";

    for(Int i = 0; i < (k-s-1)%p; i++){
        Int c = count(n);
        n += c;
        n %= 100000;
    }
    cout << n << "\n";
    // cout << mv[k-1] << "\n";
}

// 30005 = 30003+2
// 8 = 6+2
// // 1 8 3 4 5 3 4 5 3 4 5
// s = 2
// p = 3

// 8
// 2 6 4 8 1 5 1 5 1 5