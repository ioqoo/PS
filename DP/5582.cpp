#include <bits/stdc++.h>
#define MAX 4005

using namespace std;

int dp[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int str1_size = str1.size();
    int str2_size = str2.size();

    for (int i=1;i<=str1_size;i++){
        for (int j=1;j<=str2_size;j++){
            char char1 = str1[i-1], char2 = str2[j-1];
            if (char1 == char2) dp[i][j] = dp[i-1][j-1] + 1;
        }
    }

    int ans = 0;
    for (int i=1;i<=str1_size;i++){
        for (int j=1;j<=str2_size;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

}
