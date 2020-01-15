#include <bits/stdc++.h>
#define ll long long
#define MAX 100005

using namespace std;

int N;
ll dp[MAX][3];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    dp[1][0] = 1LL;
    dp[1][1] = 1LL;
    dp[1][2] = 1LL;
    for (int i=2;i<=N;i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 9901LL;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901LL;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901LL;
    }
    printf("%lld\n", (dp[N][0] + dp[N][1] + dp[N][2]) % 9901LL);
}
