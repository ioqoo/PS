#include <bits/stdc++.h>
#define MAX 505
#define INF 987654321

using namespace std;

int T, N;
int file[MAX];
int psum[MAX];
int dp[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int x=0;x<T;x++){
        memset(dp, 0, sizeof(dp));
        memset(psum, 0, sizeof(psum));

        scanf("%d", &N);
        for (int i=1;i<=N;i++){
            scanf("%d", &file[i]);
        }
        for (int i=1;i<=N;i++){
            psum[i] = psum[i-1] + file[i];
        }

        for (int i=1;i<=N-1;i++){
            dp[i][i+1] = file[i] + file[i+1];
        }

        for (int d=2;d<=N-1;d++){
            for (int i=1;i<=N-d;i++){
                int j = i+d;
                int curr_min = INF;
                for (int k=i;k<j;k++){
                    curr_min = min(curr_min, dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = curr_min + psum[j] - psum[i-1];
            }
        }

        printf("%d\n", dp[1][N]);
    }
}
