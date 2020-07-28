#include <bits/stdc++.h>

using namespace std;

int N, M;
int grid[105][105];
bool black[105][105];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &M);
    for (int i=0;i<N+2;i++){
        for (int i=0;i<M+2;i++){
            scanf("%d", &grid[i][j]);
        }
    }
    
    if (grid[0][0] == 1) black[1][1] = 1;
    if (grid[0][M+1] == 1) black[1][M] = 1;
    else {
        if (black[1][M] == 1){
            printf("impossible\n");
            return 0;
        }
    }
    if (grid[N+1][0] == 1) black[N][1] = 1;
    else{
        if (black[N][1] == 1){
            printf("impossible\n");
            return 0;
        }
    }
    if (grid[N+1][M+1] == 1) black[N][M] = 1;
    else{
        if (black[N][M] == 1){
            printf("impossible\n");
            return 0;
        }
    }
    
    for (int 

    return 0;
}



