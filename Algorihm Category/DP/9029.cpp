#include <bits/stdc++.h>

#define trisort(a, b, c) if(a > b) swap(a,b); if (b > c) swap(b, c); if (a > b) swap(a, b);

const int INF = 1e9 + 7;
const int MAX = 202;

using namespace std;

int dp[MAX][MAX][MAX];

int solve(int a, int b, int c){
    trisort(a, b, c);
    if (a == b && b == c) return 0;
    
    int &ret = dp[a][b][c];
    if (ret != 0) return ret;
    
    ret = INF;
    for (int i=1;i<=a/2;i++) {
        ret = min(ret, solve(i, b, c) + solve(a-i, b, c) + 1);
    }
    for (int i=1;i<=b/2;i++){
        ret = min(ret, solve(a, i, c) + solve(a, b-i, c) + 1);
    }
    for (int i=1;i<=c/2;i++){
        ret = min(ret, solve(a, b, i) + solve(a, b, c-i) + 1);
    }
    return ret;
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c;
//        memset(dp, 0, sizeof(dp));
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", solve(a, b, c) + 1);
    }

    return 0;
}



