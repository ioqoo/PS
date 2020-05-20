#include <bits/stdc++.h>
#define MAX 10005
#define pii pair<int, int>

using namespace std;

int T, K;
pii coins[105];
int dp[105][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &T, &K);
    for (int i=1;i<=K;i++){
        int p, n;
        scanf("%d %d", &p, &n);
        coins[i] = pii(p, n);
    }

    sort(coins+1, coins+K+1);


    for (int i=0;i<=K;i++){
        dp[i][0] = 1;
    }

    for (int i=1;i<=K;i++){
        int curr_coin = coins[i].first, curr_cnt = coins[i].second;
        for (int j=1;j<=T;j++){
            if (j < curr_coin){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            for (int k=0;k<=curr_cnt;k++){
                if (j - k * curr_coin < 0) continue;
                dp[i][j] += dp[i-1][j - k * curr_coin];
            }
        }
    }

    printf("%d\n", dp[K][T]);
}
