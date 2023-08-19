#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long int x[n],y[n],h[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    for(int cx = 0; cx <= 100; cx++){    
        for(int cy = 0; cy <= 100; cy++){
            long long int CH = -1;
            for(int i = 0; i < n; i++){
                if(h[i] == 0) continue;
                long long int H = h[i] + abs(cx-x[i]) + abs(cy-y[i]);
                if(CH == -1) CH = H;
            }
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(max<long long int>(CH - abs<long long int>(cx - x[i]) - abs<long long int>(cy - y[i]), 0) != h[i]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                printf("%d %d %lld\n", cx, cy, CH);
                return 0;
            }            
        }
    }
}
