#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

const int maxn = 35;
const double eps = 1e-7;
const double lambda = 0.98;

double x[maxn],y[maxn],z[maxn];
double gans, nx, ny, nz, T, gx, gy, gz, ans, dis;
int n;

double dist(double x1, double y1, double z1, double x2, double y2, double z2){
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double unif(){
    return (double) rand() / RAND_MAX;
}

int main(){
    srand(114514);
    while(scanf("%d",&n),n){
        for(int i = 0; i < n; ++i)
            scanf("%lf%lf%lf", x+i, y+i, z+i);
        
        gans = 1e30;

        for(int _ = 0; _ < 10; ++_){
            nx = unif() * 100;
            ny = unif() * 100;
            nz = unif() * 100;
            T = sqrt(3) * 100;

            while(T > eps){
                // Compute distance and gradient
                ans = 0;
                for(int i = 0; i < n; ++i){
                    dis = dist(nx,ny,nz,x[i],y[i],z[i]);
                    if(dis > ans){
                        ans = dis;
                        gx = (nx - x[i]) / dis;
                        gy = (ny - y[i]) / dis;
                        gz = (nz - z[i]) / dis;
                    }
                }

                if(ans < gans)
                    gans = ans;
                
                nx -= gx * T;
                ny -= gy * T;
                nz -= gz * T;

                T *= lambda;
            }
        }
        printf("%.5lf\n", gans);
    }
    return 0;
}