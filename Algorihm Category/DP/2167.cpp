#include <bits/stdc++.h>
#define ll long long
#define MAX 305

using namespace std;

int N, M, K;
int grid[MAX][MAX];
int psum[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            scanf("%d", &grid[i][j]);
        }
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            psum[i][j] = grid[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }

    scanf("%d", &K);
    for (int i=0;i<K;i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int ans = psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1];
        printf("%d\n", ans);
    }
}
