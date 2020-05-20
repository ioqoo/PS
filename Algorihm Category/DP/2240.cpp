#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int T, W;
int dp[3][MAX][33];
int pos[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &T, &W);
    for (int i=1;i<=T;i++){
        scanf("%d", &pos[i]);
    }

    for (int i=1;i<=T;i++){
        for (int j=1;j<=W+1;j++){
            if (pos[i] == 1){
                dp[1][i][j] = max(dp[2][i-1][j-1], dp[1][i-1][j]) + 1;
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]);
            }
            else{
                if (i==1 && j==1) continue;

                dp[1][i][j] = max(dp[1][i-1][j], dp[2][i-1][j-1]);
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]) + 1;
            }

        }
    }
    int ans = 0;
    for (int j=1;j<=W+1;j++){
        ans = max(ans, max(dp[1][T][j], dp[2][T][j]));
    }
    printf("%d\n", ans);
}
