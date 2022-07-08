//INCLUDE
//------------------------------------------
#include <bits/stdc++.h>
//DEFINE
//------------------------------------------
typedef long long int Int;
typedef long double Double;
#define dcml(n) fixed<<setprecision(n)
#define YES cout<<"Yes\n",exit(0)
#define NO cout<<"No\n",exit(0)
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
#define   FOR(i,k,n)   for(Int (i)=(k);     (i)<(n);  (i)++)
//-----------------------------------------
//namespace
using namespace std;
//ライブラリはここに
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//-----------------------------------------
int main(void){
    int n;cin>>n;
    vector<int> x(n),y(n),r(n);REP(i,n)cin>>x[i]>>y[i]>>r[i];
    

    double Ax[n],Ay[n],Bx[n],By[n];
    REP(i,n-1){
        int a,b,c;
        a=2*(x[i+1]-x[i]);
        b=2*(y[i+1]-y[i]);
        c=( (x[i]+x[i+1])*(x[i]-x[i+1]) + (y[i]+y[i+1])*(y[i]-y[i+1]) + (r[i+1]+r[i])*(r[i+1]-r[i]) );

        int D=abs(a*x[i]+b*y[i]+c);
        Ax[i]=( a*D-b*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+x[i];
        Ay[i]=( b*D+a*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+y[i];
        Bx[i]=( a*D+b*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+x[i];
        By[i]=( b*D-a*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+y[i];
    }

    double X[n][3],Y[n][3];
    REP(i,n-1)REP(k,3){
        if(k==0){
            X[i][0]=x[i];
            Y[i][0]=y[i];
        }else if(k==1){
            X[i][1]=Ax[i];
            Y[i][1]=Ay[i];
        }else{
            X[i][2]=Bx[i];
            Y[i][2]=By[i];
        }
    }
    X[n-1][0]=x[n-1];
    Y[n-1][0]=y[n-1];

    auto dist = [](double x1, double y1, double x2, double y2) {
        return sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) );
    };
    double d[n][3][n][3];
    REP(i,n)REP(k1,3){
        REP(j,n)REP(k2,3){
            d[i][k1][j][k2]=dist(X[i][k1],Y[i][k1],X[j][k2],Y[j][k2]);
        }
    }
    double dp[n+1][3];REP(i,n+1)REP(j,3)dp[i][j]=1e9;
    dp[0][0]=0;
    dp[0][1]=d[0][0][0][1];
    dp[0][2]=d[0][0][0][2];

    REP(i,n-1){
        printf("(x,y): (%d,%d), A,B: (%lf,%lf),(%lf,%lf)\n", x[i],y[i],Ax[i],Ay[i],Bx[i],By[i]);
        printf("(x,y): (%lf,%lf), A,B: (%lf,%lf),(%lf,%lf)\n", X[i][0],Y[i][0],X[i][1],Y[i][1],X[i][2],Y[i][2]);
    
        for(int j=i+1;j<n;j++){
            REP(k1,3){
                REP(k2,3){
                    chmin(dp[j][k2],dp[i][k1]+d[i][k1][j][k2]);
                }
            }
        }

    }
    REP(i,n)REP(k1,3){
        cout<<dcml(5)<<dp[i][k1]<<"\n";
    }
    cout<<dcml(5)<<dp[n-1][0]<<"\n";
}