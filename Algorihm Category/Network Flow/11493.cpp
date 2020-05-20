#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

const int INF = 987654321;
const int MAX = 1005;
const int S = 1002;
const int E = 1003;

using namespace std;

int T, N, M;
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX], w[MAX][MAX];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));
        for (int i=0;i<MAX;i++){
            graph[i].clear();
        }
        int u, v;
        for (int i=0;i<M;i++){
            scanf("%d %d", &u, &v); // 0, 2, 4 : in, 1, 3, 5 : out
            u--; v--;
            int uin = u*2, uout = u*2+1, vin = v*2, vout = v*2+1;
            graph[uin].push_back(uout);
            graph[uout].push_back(uin);
            graph[vin].push_back(vout);
            graph[vout].push_back(vin);
            c[uin][uout] = INF;
            c[vin][vout] = INF;
            
            graph[uout].push_back(vin);
            graph[vin].push_back(uout);
            graph[vout].push_back(uin);
            graph[uin].push_back(vout);
            c[uout][vin] = INF;
            c[vout][uin] = INF;
            w[uout][vin] = 1;
            w[vin][uout] = -1;
            w[vout][uin] = 1;
            w[uin][vout] = -1;
        }
        
        int color = -1;
        int black = 0;
        for (int i=0;i<N;i++){
            scanf("%d", &color);
            if (color == 0) {
                black++;
                graph[i*2+1].push_back(E);
                graph[E].push_back(i*2+1);
                c[i*2+1][E] = 1;
            }
        }
        for (int i=0;i<N;i++){
            scanf("%d", &color);
            if (color == 0){
                graph[S].push_back(i*2);
                graph[i*2].push_back(S);
                c[S][i*2] = 1;
            }
        }
        
        int totalw = 0;
        while(black--){
            int pre[MAX], dist[MAX];
            bool inQ[MAX] = {0,};
            fill(pre, pre+MAX, -1);
            fill(dist, dist+MAX, INF);
            queue<int> Q;
            dist[S] = 0;
            Q.push(S);
            inQ[S] = true;
            while(!Q.empty()){
                int curr = Q.front(); Q.pop(); inQ[curr] = false;
                for (int next: graph[curr]){
                    if (c[curr][next] - f[curr][next] > 0 && dist[curr] + w[curr][next] < dist[next]){
                        dist[next] = dist[curr] + w[curr][next];
                        pre[next] = curr;
                        if (!inQ[next]){
                            Q.push(next);
                            inQ[next] = true;
                        }
                    }
                }
            }
            
            if (pre[E] == -1) break;
            
            for (int i=E;i!=S;i=pre[i]){
                totalw += w[pre[i]][i];
                f[pre[i]][i]++;
                f[i][pre[i]]--;
            }
        }
        printf("%d\n", totalw);
        
    }

    return 0;
}



