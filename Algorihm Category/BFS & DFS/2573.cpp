#include <bits/stdc++.h>
#define MAX 303

using namespace std;

int N, M;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int ans;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int dgrid[MAX][MAX];

void melting(int i, int j){
    for (int d=0;d<4;d++){
        int ni = i + di[d], nj = j + dj[d];
        if (ni <= 0 || ni > N || nj <= 0 || nj > M) {
            continue;
        }
        if (grid[ni][nj] > 0){
            dgrid[ni][nj]++;
        }
    }
}

void DFS(int i, int j){
    visited[i][j] = true;

    for (int d=0;d<4;d++){
        int ni = i + di[d], nj = j + dj[d];
        if (ni <= 0 || ni > N || nj <= 0 || nj > M) continue;
        if (grid[ni][nj] != 0 && !visited[ni][nj]){
            DFS(ni, nj);
        }
    }
}

int splited(){
    int comp = 0;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            if (grid[i][j] != 0 && !visited[i][j]){
                DFS(i, j);
                comp++;
            }
        }
    }
    return comp;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            scanf("%d", &grid[i][j]);
        }
    }

    while(true){
        ans++;
        memset(visited, 0, sizeof(visited));
        memset(dgrid, 0, sizeof(dgrid));
        for (int i=1;i<=N;i++){
            for (int j=1;j<=M;j++){
                if (grid[i][j] == 0) {
                    melting(i, j);
                }
            }
        }
        for (int i=1;i<=N;i++){
            for (int j=1;j<=M;j++){
                grid[i][j] = max(0, grid[i][j] - dgrid[i][j]);
            }
        }
        if (splited() != 1){
            break;
        }
    }
    memset(visited, 0, sizeof(visited));
    printf("%d\n", splited()==0 ? 0 : ans);
}
