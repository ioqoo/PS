#include <bits/stdc++.h>
#define MAX 105

using namespace std;

int N, S, M;
int vol[MAX];
bool dp[MAX][1001];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d", &N, &S, &M);
    for (int i=1;i<=N;i++){
        scanf("%d", &vol[i]);
    }

    dp[0][S] = true;
    for (int i=1;i<=N;i++){
        int curr_d = vol[i];
        for (int j=0;j<=M;j++){
            if (dp[i-1][j]) {
                int nd = j - curr_d, pd = j + curr_d;
                if (0<= nd && nd <= M) dp[i][nd] = true;
                if (0<= pd && pd <= M) dp[i][pd] = true;
            }
        }
    }
//    for (int i=1;i<=N;i++){
//        for (int j=0;j<=M;j++){
//            printf("%d ", dp[i][j]);
//        }
//        printf("\n");
//    }
    int max_id = -1;
    for (int i=0;i<=M;i++){
        if (dp[N][i]) {
            max_id = max(max_id, i);
        }
    }
    printf("%d\n", max_id == -1 ? -1 : max_id);
}
