#include <bits/stdc++.h>
#define MAX 1234

using namespace std;

int N;
int A[MAX];
bool dp[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    if (N == 1) {
        printf("0\n");
        return 0;
    }
    for (int i=1;i<=N;i++){
        scanf("%d", &A[i]);
    }

    dp[0][1] = true;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (dp[i-1][j]) {
                dp[i][j] = true;
                for (int d=1;d<=A[j];d++){
                    dp[i][j+d] = true;
                    if (j+d == N){
                        printf("%d\n", i);
                        return 0;
                    }
                }
            }
        }
    }
//    for (int i=0;i<=N;i++){
//        for (int j=1;j<=N;j++){
//            printf("%d ", dp[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    printf("-1\n");

}
