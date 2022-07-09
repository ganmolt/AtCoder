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
constexpr int32_t MOD=998244353;

ll mpowll(ll x, ll n, ll MOD=MOD){
    if(n==0) return 1;
    if(n%2) return x*mpowll(x*x%MOD,n/2)%MOD;
    return mpowll(x*x%MOD,n/2)%MOD;
}

ll mfact(ll n){
    ll a=1;
    for(int i=2;i<=n;++i) a=a*i%MOD;
    return a;
}

ll mcomb(ll n,ll m){
    if(n==0 && m==0) return 1;
    if(n<m || n<0) return 0;
    ll ans = mfact(n)*mpowll(mfact(m),MOD-2)%MOD;
    ans = ans*mpowll(mfact(n-m),MOD-2)%MOD;
    return ans;
}

int main(){
    cin.tie(0), ios::sync_with_stdio(false);
    while(true){
        A:
        ll n,k;
        cin>>n>>k;
        if(!n && !k) break;

        vll s(n),t(n);
        IA(s,n);
        IA(t,n);

        vll visit(n);
        vvll gate;
        F(i,0,n){
            cout<<t[i]<<": "<<visit[t[i]]<<"\n";
            if(!visit[i]){
                F(k,find(all(s),t[i])-s.begin(),i){
                    if(t[k]>t[i]){
                        P(0);
                        goto A;
                    }
                }
            }
            bool enter=false;
            F(j,find(all(s),t[i])-s.begin(),sz(s)){
                if(!visit[j]){
                    if(!enter) gate.emplace_back(vll());
                    visit[j]=1;
                    gate.back().emplace_back(s[j]);
                    enter=true;
                }
            }
        }
        if(sz(gate)>k){
            P(0);
            continue;
        }

        //F(i,0,sz(gate)){
        //    F(j,0,sz(gate[i])){
        //        cout<<gate[i][j]<<" ";
        //        if(j==sz(gate[i])-1) cout<<"\n";
        //    }
        //}
        //cout<<"\n";
        ll ans=1;
        ll cut=0;
        F(i,0,sz(gate)){
            F(j,0,sz(gate[i])-1){
                if(gate[i][j]<=gate[i][j+1]){
                    cut++;
                }
            }
        }
        //cout<<"cut: ";
        //P(cut);

        F(cnt,sz(gate)+1,k+1){
            ans = (ans+mcomb(cut,cnt-sz(gate)))%MOD;
        }
        P(ans);
    }
    return 0;
}