#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int MAX = 1002;

using namespace std;

int T;
int N;
int a[MAX], b[MAX];
int dp[2][100002];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &T);
    while(T--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));
        
        scanf("%d", &N);
        int totalB = 0;
        for (int i=1;i<=N;i++){
            scanf("%d %d", &a[i], &b[i]);
            totalB += b[i];
        }
        
        int ans = INF;
        // dp[i][j] : i번째 빵까지 구웠고 첫 번째 오븐이 j만큼 시간이 걸렸을 때 두 번째 오븐이 걸리는 시간의 최댓값
        // 두 번째 오븐이 걸리는 시간은 나머지 빵은 모두 오븐 2가 굽는다고 생각하고 계산 
        // 총 시간 : max(j, totalB - dp[i][j]); 
        for (int i=1;i<=N;i++){
            for (int j=0;j<=100000;j++){
                if (j >= a[i]) dp[i%2][j] = max(dp[(i+1)%2][j], dp[(i+1)%2][j-a[i]] + b[i]);
                else dp[i%2][j] = dp[(i+1)%2][j];
                ans = min(ans, max(j, totalB - dp[i%2][j]));
            }

        }

        printf("%d\n", ans);
    }

    return 0;
}



