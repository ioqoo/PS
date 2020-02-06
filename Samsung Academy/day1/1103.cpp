#include <bits/stdc++.h>
#define MAX 53

using namespace std;

int N, M;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int dp[MAX][MAX];
int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

int dfs(int i, int j){
    if (visited[i][j]){
        cout << "-1\n";
        exit(0);
    }

    if (dp[i][j]) return dp[i][j];

    visited[i][j] = true;
    for (int d=0;d<4;d++){
        int ni = i + di[d] * grid[i][j], nj = j + dj[d] * grid[i][j];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M || grid[ni][nj] == 0) continue;

        dp[i][j] = max(dp[i][j], dfs(ni, nj) + 1);
    }
    visited[i][j] = false;

    return dp[i][j];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i=0;i<N;i++){
        string row;
        cin >> row;
        for (int j=0;j<M;j++){
            char temp = row[j];
            if (temp == 'H') continue;
            else grid[i][j] = temp - '0';
        }
    }

    cout << dfs(0, 0) + 1;


    return 0;
}
