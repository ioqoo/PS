#include <bits/stdc++.h>

using namespace std;

int T;
int grid[50][50];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int x=1;x<=T;x++){
        int N;
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                scanf("%1d", &grid[i][j]);
            }
        }
        int ans = 0;
        for (int i=0;i<=N/2;i++){
            for (int j=N/2 - i; j<= N/2 + i;j++){
                ans += grid[i][j];
            }
        }
        for (int i=N/2 + 1; i< N;i++){
            for (int j=N/2 - (N - i) + 1; j<= N/2 + (N-i) - 1; j++){
                ans += grid[i][j];
            }
        }
        printf("#%d %d\n", x, ans);
    }
    return 0;
}
