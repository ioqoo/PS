#include <bits/stdc++.h>

using namespace std;

int N, K;
int W[103], V[103];
int dp[102][100003];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &K);
    for (int i=1;i<=N;i++){
        scanf("%d %d", &W[i], &V[i]);
    }
    
    for (int i=1;i<=N;i++){
        for (int j=0;j<=K;j++){
            if (j-W[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n", dp[N][K]);

    return 0;
}



