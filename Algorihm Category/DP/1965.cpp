#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int N;
int num[MAX];
int dp[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &num[i]);
    }
    for (int i=1;i<=N;i++){
        int curr_max = 0;
        for (int j=0;j<i;j++){
            if (num[j] < num[i]){
                curr_max = max(curr_max, dp[j]);
            }
        }
        dp[i] = curr_max + 1;
    }
    printf("%d", *max_element(dp+1, dp+N+1));
}
