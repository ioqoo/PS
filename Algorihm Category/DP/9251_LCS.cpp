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
                // ���� �ٸ� ��� ���� ��
                // (���� �� ���� �����ư��� �� ���) �� ū ���� ä��
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);��
                // i+1, j+1�� row = 0, column = 0�� ��츦 ����α� ��
            }
            else {
                // ���� ��� ���� ��
                // (�ٸ� ���� �ٸ��� �� �� ��ο��� �� ���� �� ���) + 1
                // -> �̹� i+1, j+1��°�� ������� LCS�� �� �������̱� ����
                dp[i+1][j+1] = dp[i][j] + 1;
            }
        }
    }
    printf("%d\n", dp[str1_size][str2_size]);
}
