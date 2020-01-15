#include <bits/stdc++.h>
#define MAX 505

using namespace std;

int N, M;
int grid[MAX][MAX];
int dp[MAX][MAX];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int dfs(int a, int b){ // (0,0) ~ (a,b)���� ���� ����� �� ����
    if (a == 0 & b == 0) return 1; // base case
    if (dp[a][b] != -1) return dp[a][b]; // �湮�� �߾����� �� �� ����

    dp[a][b] = 0; // �湮 ǥ�� (�̹湮�� -1�� �ʱ�ȭ �Ǿ�����)
    for (int d=0;d<4;d++){
        int ni = a + di[d], nj = b + dj[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;

        if (grid[a][b] < grid[ni][nj]) {
            dp[a][b] += dfs(ni, nj);
        }
    }

    return dp[a][b];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &M);

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%d", &grid[i][j]);
        }
    }

    printf("%d", dfs(N-1, M-1));

}
