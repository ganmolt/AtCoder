//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
#define Int long long
#define Double long double
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
Int N;
typedef pair<Int,Int> P;
Double p1p2(P p1,P p2){
    Int x=p2.first-p1.first;
    Int y=p2.second-p1.second;
    return atan2(y,x)*180/PI;
};
//-----------------------------------------
int main(void){
    cin>>N;
    vector<P> v(N);
    REP(i,N){
        cin>>v[i].first>>v[i].second;
    }
    Double ans=-1;
    //Pjを決め打ち ：：∠PiPjPk
    for(int j=0;j<N;j++){
        //cout<<j<<",,,"<<v[j].first<<","<<v[j].second<<":\n";
        vector<pair<Double,int>> D;//値,相手のidx
        for(int a=0;a<N;a++){
            if(j!=a)D.push_back({p1p2(v[j],v[a]),a});
        }sort(D.begin(),D.end());
        //for(int a=0;a<D.size();a++)cout<<D[a].first<<" ";cout<<"\n";
        for(int i=0;i<N;i++){
            if(j==i)continue;
            //iを決めるとkも決まる
            Double v1=p1p2(v[j],v[i]);
            //cout<<"v1: "<<i<<","<<v1<<",";
            int k;
            //偏角ソートしたもので、t+180に近い物を選ぶ
            Double want=(v1+180>360?v1+180-360:v1+180);
            //cout<<want;
            int idx1=lower_bound(D.begin(),D.end(),make_pair(want,0))-D.begin();//これか、1つ前
            if(idx1==D.size())idx1=0;
            int idx2=(idx1>=1?idx1-1:D.size()-1);
            //cout<<"(i1,i2)=("<<idx1<<","<<idx2<<") ";
            //cout<<D[idx1].first<<","<<D[idx2].first<<" ";
            Double v2;
            Double v2_1=min(abs(v1-D[idx1].first),360-abs(v1-D[idx1].first));
            Double v2_2=min(abs(v1-D[idx2].first),360-abs(v1-D[idx2].first));
            if(v2_1<v2_2){
                v2=v2_2;
                k=idx2;
            }
            else{
                v2=v2_1;
                k=idx1;
            }
            if(j==k){
                //cout<<"\n";
                continue;
            }
            //cout<<"v2: "<<k<<","<<v2;
            ans=max(ans,v2);
            //cout<<"\n";
        }
    }
    cout<<dcml(13)<<ans<<"\n";


    /*
    //各頂点同士のベクトル
    vector<bekutoru> vv;
    REP(i,N-1){
        for(int j=i+1;j<N;j++){
            vv.push_back(bekutoru(v[i],v[j]));
        }
    }
    sort(vv.begin(),vv.end());
    Double ansm=100;
    Double ansM=-100;
    for(int i=1;i<vv.size();i++){
        if()
        chmin(ansm,vv[i]-vv[i-1]);
        chmax(ansM,vv[i]-vv[i-1]);
    }
    chmin(ansm,vv[0]-vv[vv.size()-1]);
    chmax(ansM,vv[0]-vv[vv.size()-1]);

    Double ansmm=ansm*(180.0/PI);
    while(ansmm<0)ansmm+=180;
    while(ansmm>180)ansmm-=180;
    Double ansMM=ansM*(180.0/PI);
    while(ansMM<0)ansMM+=180;
    while(ansMM>180)ansMM-=180;
    cout<<ansmm<<","<<ansMM<<"\n";
    */
}

//同じ頂点を共有する必要がある