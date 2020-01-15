#include <bits/stdc++.h>
#define MAX 505
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

int N;
pii mat[MAX];
int dp[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        mat[i] = pii(a, b);
    }
    dp[1] = mat[1].fi * mat[1].se;
    dp[2] = mat[1].fi * mat[2].fi * mat[2].se;
    for (int i=3;i<=N;i++){
        dp[i] = min(dp[i-1] + mat[1].fi * mat[i].fi * mat[i].se, mat[i-1].fi * mat[i].fi * mat[i].se + dp[i-1] * mat[i].se);
    }

    printf("%d\n", dp[N]);

}
