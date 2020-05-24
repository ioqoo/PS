#include <bits/stdc++.h>

const int MAX = 51;
using namespace std;

int grid[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        memset(grid, 0, sizeof(grid));
        int N;
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                scanf("%1d", &grid[i][j]);
//                printf("%d ", grid[i][j]);
            }
//            printf("\n");
        }
        bool succ = true;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (grid[i][j] == 1){
                    if (j+1 != N && i+1 != N){
                        if (grid[i+1][j] != 1 && grid[i][j+1] != 1){
                            printf("NO\n");
                            succ = false;
                            break;
                        }
                    }
                }
            }
        }
        if (succ) printf("YES\n");
    }

    return 0;
}



