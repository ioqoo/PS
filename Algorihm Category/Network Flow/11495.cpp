#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

const int MAX = 52;
const int S = 2501;
const int E = 2502;
const int INF = 987654321;

using namespace std;

int T, N, M, all;
int grid[MAX][MAX];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int c[MAX*MAX][MAX*MAX], f[MAX*MAX][MAX*MAX];

int convert(int i, int j) {
    return (i*M+j);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &N, &M);
        all = 0;
        memset(grid, 0, sizeof(grid));
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        vector<int> graph[MAX*MAX];
        
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                scanf("%d", &grid[i][j]);
                all += grid[i][j];
            }
        }
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                int node = convert(i, j);
                if (i%2 == 0){
                    if (j%2==0){
                        graph[S].push_back(node);
                        graph[node].push_back(S);
                        c[S][node] = grid[i][j];
                    }
                    else {
                        graph[node].push_back(E);
                        graph[E].push_back(node);
                        c[node][E] = grid[i][j];
                    }
                }
                else{
                    if (j%2 == 0){
                        graph[node].push_back(E);
                        graph[E].push_back(node);
                        c[node][E] = grid[i][j];                        
                    }
                    else{
                        graph[S].push_back(node);
                        graph[node].push_back(S);
                        c[S][node] = grid[i][j];
                    }
                }
                for (int d=0;d<4;d++){
                    int ni = i+di[d], nj = j+dj[d];
                    if (ni<0 || ni >= N || nj < 0 || nj >= M) continue;
                    int next = convert(ni, nj);
                    graph[node].push_back(next);
                    if (i%2 == 0 && j%2 == 1) continue;
                    if (i%2 == 1 && j%2 == 0) continue;
                    c[node][next] = INF;
                }
            }
        }
        
        int total = 0;
        while(1){
            int pre[MAX*MAX];
            memset(pre, -1, sizeof(pre));
            queue<int> Q;
            Q.push(S);
            while(!Q.empty() && pre[E] == -1){
                int curr = Q.front(); Q.pop();
                for (int next: graph[curr]){
                    if (c[curr][next] - f[curr][next] > 0 && pre[next] == -1){
                        pre[next] = curr;
                        Q.push(next);
                        if (next == E) break;
                    }
                }
            }
            if (pre[E] == -1) break;
            
            int flow = INF;
            for (int i=E;i!=S;i=pre[i]){
                flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
            }
            for (int i=E;i!=S;i=pre[i]){
                f[pre[i]][i] += flow;
                f[i][pre[i]] -= flow;
            }
            total += flow;
        }
        printf("%d\n", all - total);
        
        
    }

    return 0;
}



