#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll,ll>;
using vp = vector<pll>;
using graph = vector<vector<pll>>;
#define all(a) a.begin(),a.end()
#define F(index,start,end) for(ll index=start;index<end;++index)
#define IA(array,size) F(index,0,size) cin >> array[index]
#define IA2(array,height,width) F(i,0,height) F(j,0,width) cin >> array[i][j]
#define PA(array,size) F(index,0,size) { cout << array[index]; if(index!=size-1) cout << " ";} cout << endl
#define PA2(array,height,width) F(i,0,height) {F(j,0,width) cout << array[i][j]<< (j!=width-1?" ":""); cout << endl;}
#define P(str) cout << str << endl
#define setP(str,num) cout << fixed << setprecision(num) << str << endl
#define sz(str) ll(str.size())
constexpr int64_t INF=1ll<<60;
constexpr int32_t MOD=1000000007;

//void f(vll& c){ // ダブり消す
//    ll size=sz(c);
//    F(ai,0,size){
//        bool d=false;
//        F(bi,0,sz(c)){
//            if(c[ai]==c[bi]){
//                ll aa=ai,bb=bi;
//                if(aa>bb) swap(aa,bb);
//                c.erase(c.begin()+aa,c.begin()+aa+1);
//                c.erase(c.begin()+bb-1,c.begin()+bb);
//                d=true;
//                break;
//            }
//        }
//    }
//}

int main(){
    cin.tie(0), ios::sync_with_stdio(false);
    while(true){
        ll n;
        cin>>n;
        if(!n) break;

        vvll c(n,vll(2));
        IA2(c,n,2);
        F(i,0,n) sort(all(c[i]));

        F(i,0,n){
            if(c[i][0]==c[i][1]){
                c[i].clear();
            }
        }

        ll i=0;
        ll ans=0;
        bool finish=false;
        while(!finish){
            if(c[i%n].empty()){
                i=(i+1)%n;
                continue;
            }

            ++ans;

            ll j=(i+1)%n;
            while(i!=j && c[j].empty()) j=(j+1)%n;
            bool d=false;
            F(ai,0,sz(c[j])){
                if(c[j][ai]==c[i][0]){
                    c[j].erase(c[j].begin()+ai,c[j].begin()+ai+1);
                    d=true;
                    break;
                }
            }
            if(!d){
                c[j].emplace_back(c[i][0]);
            }

            sort(all(c[j]));
            F(i,0,n){
                ll s=sz(c[i]);
                F(j,0,s-1){
                    if(j+1>=sz(c[i])) break;
                    if(c[i][j]==c[i][j+1]){
                        c[j].erase(c[j].begin()+j,c[j].begin()+j+2);
                        j=0;
                    }
                }
            }

            F(i,0,n) finish &= c[i].empty();
        }
        P(ans);
    }
    return 0;
}