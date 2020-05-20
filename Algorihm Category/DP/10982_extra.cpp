#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;

int T, N;
int a[101], b[101];
int dp[2][100222];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        
        for (int i=1;i<=N;i++){
            scanf("%d %d", &a[i], &b[i]);
        }
        
        dp[1][a[1]] = 0;
        dp[1][0] = b[1];
        
        for (int i=2;i<=N;i++){
            for (int j=0;j<=100000;j++){
                dp[0][j+a[i]] = min(dp[0][j+a[i]], dp[1][j]);
                dp[0][j] = min(dp[0][j], dp[1][j] + b[i]);
            }
            for (int j=0;j<=100000;j++){
                int temp = dp[0][j];
                dp[1][j] = temp;
                dp[0][j] = INF;
            }
        }
        int ans = INF;
//        for (int i=0;i<=60;i++){
//            printf("%d\n", dp[1][i]);
//        }
        for (int j=0;j<=100000;j++){
            ans = min(ans, max(j, dp[1][j]));
        }
        printf("%d\n", ans);
    }

    return 0;
}



