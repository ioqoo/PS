#include <bits/stdc++.h>
#define MAX 41

using namespace std;

int N, M;
bool vip[MAX];
int dp[MAX];
int ans = 1;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++){
        int temp;
        scanf("%d", &temp);
        vip[temp] = true;
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    int curr = 0;
    for (int i=1;i<=N;i++){
        if (vip[i]){
            ans *= dp[curr];
            curr = 0;
        }
        else{
            curr++;
        }
    }
    ans *= dp[curr];

    printf("%d\n", ans);
}
