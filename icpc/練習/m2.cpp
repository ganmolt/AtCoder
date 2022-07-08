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
const Double eps=1e-12;
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
    while(true){
        int n;cin>>n;
        vector<Double> x(n),y(n),r(n);REP(i,n)cin>>x[i]>>y[i]>>r[i];
        

        Double Ax[n],Ay[n],Bx[n],By[n];
        REP(i,n-1){
            Double a,b,c;
            a=2*(x[i+1]-x[i]);
            b=2*(y[i+1]-y[i]);
            c=( (x[i]+x[i+1])*(x[i]-x[i+1]) + (y[i]+y[i+1])*(y[i]-y[i+1]) + (r[i+1]+r[i])*(r[i+1]-r[i]) );

            Double D=abs(a*x[i]+b*y[i]+c);
            Ax[i]=( a*D-b*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+x[i];
            Ay[i]=( b*D+a*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+y[i];
            Bx[i]=( a*D+b*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+x[i];
            By[i]=( b*D-a*sqrt((a*a+b*b)*r[i]*r[i]-D*D) )/( a*a+b*b )+y[i];
        }

        Double X[n][3],Y[n][3];
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

        auto dist = [](Double x1, Double y1, Double x2, Double y2) {
            return sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) );
        };
        struct Func{
            static tuple<Double,Double,Double> abcd(Double a, Double b, Double c, Double d) {
                return {d-b, a-c, (b-d)*a+(c-a)*b};
            }

            static pair<Double,Double> makeXY(tuple<Double,Double,Double> t1, tuple<Double,Double,Double> t2){
                Double a1,a2,b1,b2,c1,c2;
                a1=get<0>(t1),b1=get<1>(t1),c1=get<2>(t1);
                a2=get<0>(t2),b2=get<1>(t2),c2=get<2>(t2);
                Double x,y;
                x=( (b1*c2-b2*c1) / (a1*b2-a2*b1) );
                y=( (a2*c1-a1*c2) / (a1*b2-a2*b1) );
                return {x,y};
            }

            static bool isIn_r(pair<Double,Double> xy, Double x1, Double y1, Double x2, Double y2){
                Double x=xy.first;
                Double y=xy.second;
                if( ( min(x1,x2)-eps <= x && x <= max(x1,x2)+eps ) && ( min(y1,y2)-eps <= y && y <= max(y1,y2)+eps ) ){
                    return true;
                }else{
                    return false;
                }
            }
        };
        
        Double d[n][3][n][3];
        REP(i,n)REP(k1,3){
            REP(j,n)REP(k2,3){
                d[i][k1][j][k2]=dist(X[i][k1],Y[i][k1],X[j][k2],Y[j][k2]);
            }
        }
        Double dp[n+1][3];REP(i,n+1)REP(j,3)dp[i][j]=1e9;
        dp[0][0]=0;
        dp[0][1]=d[0][0][0][1];
        dp[0][2]=d[0][0][0][2];

        REP(i,n-1){
            //printf("(x,y): (%d,%d), A,B: (%lf,%lf),(%lf,%lf)\n", x[i],y[i],Ax[i],Ay[i],Bx[i],By[i]);
            //printf("(x,y): (%llf,%llf), A,B: (%lf,%lf),(%lf,%lf)\n", X[i][0],Y[i][0],X[i][1],Y[i][1],X[i][2],Y[i][2]);
        
            REP(k1,3){
                for(int j=i+1;j<n;j++){
                    REP(k2,3){
                        //式[i][k1]-[j][k2]をもっておく
                        tuple<Double,Double,Double> abc1=Func::abcd( X[i][k1], Y[i][k1], X[j][k2], Y[j][k2] );
                        bool NOOOOOOOO=false;
                        for(int l=i+1;l<j;l++){
                            //と直線[l]の交点が
                            //( min(x0,x1) <= x <= max(x0,x1) ) && ( min(y0,y1) <= y <= max(y0,y1) )
                            tuple<Double,Double,Double> abc2=Func::abcd( X[l][1], Y[l][1], X[l][2], Y[l][2] );
                            //平行の時の処理したほうがよいかも(?)
                            pair<Double,Double> xy=Func::makeXY(abc1, abc2);
                            if(Func::isIn_r(xy, X[l][1], Y[l][1], X[l][2], Y[l][2]))continue;
                            else{
                                NOOOOOOOO=true;
                                break;
                            }
                        }
                        if(NOOOOOOOO)break;
                        chmin(dp[j][k2],dp[i][k1]+d[i][k1][j][k2]);
                    }
                }
            }

        }
        
        /*
        REP(i,n)REP(k1,3){
            cout<<dcml(5)<<dp[i][k1]<<"\n";
        }*/
        cout<<dcml(5)<<dp[n-1][0]<<"\n";
    }
}