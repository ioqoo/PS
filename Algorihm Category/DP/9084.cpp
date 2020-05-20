#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

int T, N, M;
int coin[21];
int dp[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int x=0;x<T;x++){
        memset(dp, 0, sizeof(dp));

        scanf("%d", &N);
        for (int i=1;i<=N;i++){
            scanf("%d", &coin[i]);
        }
        scanf("%d", &M);

        dp[coin[0]] = 1;
        for (int i=1;i<=N;i++){
            for (int j=coin[i];j<=M;j++){
                dp[j] += dp[j - coin[i]];
            }
        }
        printf("%d\n", dp[M]);

    }
}
