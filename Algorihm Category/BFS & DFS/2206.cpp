#include <iostream>
#include <queue>

#define MAX 1005
#define INF 987654321
#define pii pair<int, int>

using namespace std;

int N, M;
int grid[MAX][MAX];
queue<pair<pii, bool>> Q;
bool visited[MAX][MAX][2];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int dist[MAX][MAX][2];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%1d", &grid[i][j]);
            dist[i][j][0] = dist[i][j][1] = INF;
        }
    }
    
    Q.push({{0, 0}, false});
    dist[0][0][0] = 1;
    visited[0][0][0] = visited[0][0][1] = true;
    while(!Q.empty()){
        auto p = Q.front();
        Q.pop();
        int ci = p.first.first, cj = p.first.second;
        bool breaked = p.second;
        for (int d=0;d<4;d++){
            int ni = ci + di[d], nj = cj + dj[d];
            if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
//            if (visited[ni][nj]) continue;
            if (breaked){
                if (grid[ni][nj] == 1) continue;
                if (visited[ni][nj][1]) continue;
                Q.push({{ni, nj}, true});
                visited[ni][nj][1] = true;
                dist[ni][nj][1] = min(dist[ni][nj][1], dist[ci][cj][1] + 1);
            }
            else{
                if (grid[ni][nj] == 1) {
                    if (visited[ni][nj][1]) continue;
                    visited[ni][nj][1] = true;
                    Q.push({{ni, nj}, true});
                    dist[ni][nj][1] = min(dist[ni][nj][1], dist[ci][cj][0] + 1);
                }
                else {
                    if (visited[ni][nj][0]) continue;
                    visited[ni][nj][0] = true;
                    Q.push({{ni, nj}, false});
                    dist[ni][nj][0] = min(dist[ni][nj][0], dist[ci][cj][0] + 1);
                }
            }
        }
    }
    int ans = min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
    printf("%d\n", ans == INF ? -1 : ans);
    
    
    

    return 0;
}



