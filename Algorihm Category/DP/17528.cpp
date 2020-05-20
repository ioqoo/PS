#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int MAX = 252;
using namespace std;

int N;
int A[MAX], B[MAX];
int dp[MAX][MAX*MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d %d", &A[i], &B[i]);
    }
    
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1][A[1]] = 0;
    dp[1][0] = B[1];
    
    for (int i=2;i<=N;i++){
        for (int j=0;j<MAX*MAX;j++){
            dp[i][j+A[i]] = min(dp[i][j+A[i]], dp[i-1][j]);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + B[i]);
        }
    }
    
    int ans = INF;
    for (int i=0;i<MAX*MAX;i++){
        ans = min(ans, max(dp[N][i], i));
    }
    printf("%d\n", ans);

    return 0;
}



