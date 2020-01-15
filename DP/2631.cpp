#include <bits/stdc++.h>
#define MAX 205
#define pii pair<int, int>

using namespace std;

int N;
int nums[MAX];
int dp[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &nums[i]);
    }

    dp[1] = 1;
    for (int i=2;i<=N;i++){
        int curr_max = 0;
        for (int j=1;j<i;j++){
            if (nums[j] < nums[i]){
                curr_max = max(curr_max, dp[j]);
            }
        }
        dp[i] = curr_max + 1;
    }
    printf("%d\n", N - *max_element(dp+1, dp+N+1));
}
