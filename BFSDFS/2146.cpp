#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 105
#define INF 987654321

using namespace std;

int N;
int grid[MAX][MAX];
int conti[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int ans = INF;

void DFS(int i, int j, int num){
    visited[i][j] = true;
    conti[i][j] = num;

    for (int d=0;d<4;d++){
        int ni = i + di[d], nj = j + dj[d];
        if (ni <= 0 || ni > N || nj <= 0 || ni > N || visited[ni][nj] || grid[ni][nj] == 0) continue;
        DFS(ni, nj, num);
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            scanf("%d", &grid[i][j]);
        }
    }
    int conti_num = 0;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (!visited[i][j] && grid[i][j]){
                conti_num++;
                DFS(i, j, conti_num);
            }
        }
    }

//    for (int i=1;i<=N;i++){
//        for (int j=1;j<=N;j++){
//            printf("%d ", conti[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    for (int n=1;n<=conti_num;n++){
        int curr_min = INF;
        memset(visited, 0, sizeof(visited));
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                dist[i][j] = INF;
            }
        }

        queue<pii> q;
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                if (conti[i][j] == n){
                    q.push(pii(i, j));
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int d=0;d<4;d++){
                int ni = i + di[d], nj = j + dj[d];
                if (ni <= 0 || ni > N || nj <= 0 || nj > N || visited[ni][nj]) continue;
                dist[ni][nj] = min(dist[ni][nj], dist[i][j] + 1);
                q.push(pii(ni, nj));
                visited[ni][nj] = true;
            }
        }

        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
//                printf("%d ", dist[i][j]);
                if (conti[i][j] > 0 && conti[i][j] != n){
                    curr_min = min(curr_min, dist[i][j]);
                }
            }
//            printf("\n");
        }
//        printf("\n");
        ans = min(ans, curr_min);
    }
    printf("%d\n", ans - 1);

}
