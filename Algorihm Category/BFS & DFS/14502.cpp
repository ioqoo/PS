#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 8

using namespace std;

int N, M;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int wall_0, virus;
int ans;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int safe_area(){
    int ret = 0;

    memset(visited, 0, sizeof(visited));
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (grid[i][j] == 2){
                queue<pii> q;
                q.push(pii(i, j));
                visited[i][j] = true;
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    int i0 = p.first, j0 = p.second;
                    for (int d=0;d<4;d++){
                        int ni = i0 + di[d], nj = j0 + dj[d];
                        if (0 > ni || ni >= N || 0 > nj || nj >= M || visited[ni][nj] || grid[ni][nj] != 0) continue;
                        visited[ni][nj] = true;
                        q.push(pii(ni, nj));
                    }
                }
            }
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
//            printf("%d ", visited[i][j]);
            if (!visited[i][j]) ret++;
        }
//        printf("\n");
    }
//    printf("\n\n");
    return ret - wall_0 - 3;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            int temp;
            scanf("%d", &temp);
            if (temp == 1) wall_0++;
            if (temp == 2) virus++;
            grid[i][j] = temp;
        }
    }

    for (int i=0;i<N*M-2;i++){
        int i1 = i / M, j1 = i % M;
        if (grid[i1][j1] != 0) continue;
        grid[i1][j1] = 1;
        for (int j=i+1;j<N*M-1;j++){
            int i2 = j / M, j2 = j % M;
            if (grid[i2][j2] != 0) continue;
            grid[i2][j2] = 1;
            for (int k=j+1;k<N*M;k++){
                int i3 = k / M, j3 = k % M;
                //printf("%d %d / %d %d / %d %d\n", i1, j1, i2, j2, i3, j3);
                if (grid[i3][j3] != 0) continue;
                grid[i3][j3] = 1;
                ans = max(ans, safe_area());
                grid[i3][j3] = 0;
            }
            grid[i2][j2] = 0;
        }
        grid[i1][j1] = 0;
    }

    printf("%d\n", ans);
}
