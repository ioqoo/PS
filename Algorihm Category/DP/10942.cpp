#include <bits/stdc++.h>
#define MAX 2005

// 처음엔 diagonal 원소들만 true로 초기화 해주고
// (i, j)를 볼 때 (i, j-1)이 true면 절대 true가 될 수 없다고 생각했는데
// 11 -> 111만 봐도 반례가 있음
// 시작점을 고정해 두고 끝 점을 볼 때, 시작점과 끝점이 같으면서
// 그 사이의 문자열이 팰린드롬이면 전체도 팰린드롬이라는 아이디어는 맞았는데
// 길이가 2인 걸 초기화를 안 하고 + 위에서 true 오른쪽은 반드시 false다라고 생각해서 틀렸음

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
