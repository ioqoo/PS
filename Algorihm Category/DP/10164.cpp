#include <bits/stdc++.h>
#define MAX 17

using namespace std;

int dp[MAX][MAX];
int N, M, K;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d", &N, &M, &K);
    dp[1][1] = 1;
    if (K == 0){
        for (int i=1;i<=N;i++){
            for (int j=1;j<=M;j++){
                if (i==1 && j==1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        printf("%d\n", dp[N][M]);
    }
    else{
        int a = (K-1) / M + 1, b = (K-1) % M + 1;
        for (int i=1;i<=a;i++){
            for (int j=1;j<=b;j++){
                if (i==1 && j==1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        for (int i=a;i<=N;i++){
            for (int j=b;j<=M;j++){
                if (i==a && j==b) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        printf("%d\n", dp[N][M]);
    }


}
