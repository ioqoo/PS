#include <bits/stdc++.h>
#define MAX 1005
#define MIN -2e9

using namespace std;

int N, M;
int grid[MAX][MAX];
int dp[MAX][MAX][2];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<=N+1;i++){
        for (int j=0;j<=M+1;j++){
            dp[i][j][0] = dp[i][j][1] = MIN;
        }
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            scanf("%d", &grid[i][j]);
        }
    }

    dp[1][1][0] = grid[1][1];
    for (int j=2;j<=M;j++){
        dp[1][j][0]= grid[1][j] + dp[1][j-1][0];
    }

    for (int i=2;i<=N;i++){
        for (int j=1;j<=M;j++){
            dp[i][j][0] = grid[i][j] + max(max(dp[i-1][j][0], dp[i-1][j][1]), dp[i][j-1][0]);
        }
        for (int j=M;j>=1;j--){
            dp[i][j][1] = grid[i][j] + max(max(dp[i-1][j][0], dp[i-1][j][1]), dp[i][j+1][1]);
        }
    }

    printf("%d\n", max(dp[N][M][0], dp[N][M][1]));
}
