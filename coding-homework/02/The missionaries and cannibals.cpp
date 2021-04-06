#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1005;

int m,n;
int ans = -1;

bool in_close[maxn][maxn][2], in_open[maxn][maxn][2];

struct State{
    int miss, cann, side, step, weight;
    State(int _m=0, int _c=0, int _s=0, int __s=0, int _w=0):
        miss(_m), cann(_c), side(_s), step(__s), weight(_w) {}
    bool operator<(const State&b)const{
        return weight > b.weight;
    }
};

int calWeight(int miss, int cann, int side, int step){
    return step + miss + cann - 2*side;
}

bool safe(int miss, int cann){
    return miss == 0 || miss == m || miss == cann;
}

void AStar(){
    priority_queue<State> q;
    q.push(State(m,m,0,0,0));
    in_open[m][m][0] = true;

    State u;
    int miss, cann, side, step, nmiss, ncann, fmiss, fcann, fstep, fside, fweight, d;
    
    while(!q.empty()){
        u = q.top();
        q.pop();
        miss = u.miss; cann = u.cann; side = u.side; step = u.step;
        
        if(miss == 0 && cann == 0 && side == 1){
            ans = step;
            break;
        }

        in_close[miss][cann][side] = true;

        if(side == 0)
            nmiss = miss, ncann = cann, d = -1;
        else
            nmiss = m - miss, ncann = m - cann, d = 1;
        
        for(int i = 0; i <= nmiss; ++i)
            for(int j = 0; j <= ncann; ++j){
                if(i+j == 0 || (i != 0 && i < j))
                    continue;
                if(i+j > n)
                    break;
                fmiss = miss + d * i;
                fcann = cann + d * j;
                fstep = step + 1;
                fside = side ^ 1;
                if(!safe(fmiss, fcann)) continue;
                if(in_close[fmiss][fcann][fside])
                    continue;
                if(in_open[fmiss][fcann][fside])
                    continue;
                in_open[fmiss][fcann][fside] = true;
                fweight = calWeight(fmiss, fcann, fside, fstep);
                q.push(State(fmiss, fcann, fside, fstep, fweight));
            }
    }
}

int main(){
    scanf("%d%d", &m, &n);

    memset(in_close, 0, sizeof in_close);
    memset(in_open, 0, sizeof in_open);

    AStar();

    printf("%d\n", ans);

    return 0;
}