#include <bits/stdc++.h>

const int INF = 2e9+7;
using namespace std;

int N, K;
int cost[21][21];
int dp[1<<21];

int solve(int curr){
    if (__builtin_popcount(curr) == K) return 0;
    int &ret = dp[curr];
    if (ret != -1) return ret;
    
    ret = INF;
    // i->j
    for (int i=0;i<N;i++){
        if ((curr & (1<<i)) == 0) continue;
        for (int j=0;j<N;j++){
            if (i==j) continue;
            if ((curr & (1<<j)) == 0) continue; 
            ret = min(ret, solve(curr ^ (1<<i)) + cost[i][j]);
        }
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &K);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    printf("%d\n", solve((1<<(N)) - 1));
    
    return 0;
}



