#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int N, M;
int grid[MAX][MAX];
int dp[MAX][MAX][3];

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

    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            dp[i][j][0] = *max_element(dp[i-1][j], dp[i-1][j]+3) + grid[i][j];
            dp[i][j][1] = *max_element(dp[i][j-1], dp[i][j-1]+3) + grid[i][j];
            dp[i][j][2] = *max_element(dp[i-1][j-1], dp[i-1][j-1]+3) + grid[i][j];
        }
    }
    printf("%d\n", *max_element(dp[N][M], dp[N][M]+3));

}
