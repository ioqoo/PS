#include <bits/stdc++.h>
#define ll long long
#define MAX 1005

using namespace std;

int dp[MAX][MAX];
string str1, str2;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str1 >> str2;

    int str1_size = str1.size();
    int str2_size = str2.size();

    for (int i=0;i<str1_size;i++){
        for (int j=0;j<str2_size;j++){
            char c1 = str1[i], c2 = str2[j];
            if (c1 != c2) {
                // 만약 다를 경우 이전 비교
                // (서로 한 개씩 번갈아가며 뺀 경우) 중 큰 값을 채택
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);에
                // i+1, j+1은 row = 0, column = 0인 경우를 비워두기 위
            }
            else {
                // 같을 경우 이전 비교
                // (다를 경우와 다르게 양 쪽 모두에서 한 개씩 뺀 경우) + 1
                // -> 이번 i+1, j+1번째가 현재까지 LCS의 맨 마지막이기 때문
                dp[i+1][j+1] = dp[i][j] + 1;
            }
        }
    }
    printf("%d\n", dp[str1_size][str2_size]);
}
