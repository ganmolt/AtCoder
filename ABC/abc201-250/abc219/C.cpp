//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//CONST
//------------------------------------------
const Int INF=1010000000000000017LL;
const Int MOD=1000000007LL;
const Double EPS=1e-12;
const Double PI=3.14159265358979323846;
//REPEAT
//------------------------------------------
#define   REP(i,n)   for(Int (i)=0;     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//-----------------------------------------
string nwAlpbt;
int main(void){
    cin>>nwAlpbt;
    Int N;cin>>N;
    vector<string> S(N);
    //
    vector<int> pos(26);
    for (int i = 0; i < 26; ++i) {
        pos[nwAlpbt[i] - 'a'] = i;
    }
    //
    REP(i,N){
        cin>>S[i];
    }
    sort(S.begin(),S.end(), [&](const string& s, const string& t){
        int len=min(s.size(),t.size());
        for(int i=0;i<len;i++){
            if(s[i]!=t[i]){
                return pos[s[i]-'a'] < pos[t[i]-'a'];
            }
        }
        return s.size() < t.size();
    });
    cout<<"\n";
    
    for(auto s:S){
        cout<<s<<"\n";
    }
}

