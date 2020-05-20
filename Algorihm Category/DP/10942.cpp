#include <bits/stdc++.h>
#define MAX 2005

// ó���� diagonal ���ҵ鸸 true�� �ʱ�ȭ ���ְ�
// (i, j)�� �� �� (i, j-1)�� true�� ���� true�� �� �� ���ٰ� �����ߴµ�
// 11 -> 111�� ���� �ݷʰ� ����
// �������� ������ �ΰ� �� ���� �� ��, �������� ������ �����鼭
// �� ������ ���ڿ��� �Ӹ�����̸� ��ü�� �Ӹ�����̶�� ���̵��� �¾Ҵµ�
// ���̰� 2�� �� �ʱ�ȭ�� �� �ϰ� + ������ true �������� �ݵ�� false�ٶ�� �����ؼ� Ʋ����

using namespace std;

int N, M;
int num[MAX];
bool dp[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &num[i]);
    }
    for (int i=1;i<=N;i++){
        dp[i][i] = true;
        if (num[i] == num[i+1]) dp[i][i+1] = true;
    }
    for (int j=3;j<=N;j++){
        for (int i=1;i<j-1;i++){
            if (num[j] == num[i] && dp[i+1][j-1]){
                dp[i][j] = true;
            }
        }
    }

    scanf("%d", &M);
    for (int i=0;i<M;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
}
