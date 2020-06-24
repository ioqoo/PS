#include <bits/stdc++.h>

const int MAX = 1003;
using namespace std;

int N, M;
bool grid[MAX][MAX];
bool grid2[MAX][MAX];

void debug(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");printf("\n");
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d %d", &N, &M);
    
    for (int i=0;i<M;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        grid[u][v] = grid[v][u] = true;
        grid2[u][v] = grid2[v][u] = true;
    }
    
    // 1 push
    
    for (int j=1;j<N;j++){
        grid[0][j] ^= 1;
    }
    
    for (int i=1;i<N;i++){
        if (!grid[i-1][i]){
            for (int a=0;a<i;a++){
                grid[a][i] ^= 1;
            }
            for (int a=i+1;a<N;a++){
                grid[i][a] ^= 1;
            }
        }
        
    }
    
    bool succ = true;
    for (int i=0;i<N;i++){
        for (int j=i;j<N;j++){
            if (i==j) continue;
            if (!grid[i][j]) {
                succ = false;
                break;
            }
        }
        if (!succ) break;
    }
    

    
    if (succ) {
        printf("DA\n");
        return 0;
    }
    
    for (int i=1;i<N;i++){
        if (!grid2[i-1][i]){
            for (int a=0;a<i;a++){
                grid2[a][i] ^= 1;
            }
            for (int a=i+1;a<N;a++){
                grid2[i][a] ^= 1;
            }
        }
    }    
    
    
    bool succ2 = true;
    for (int i=0;i<N;i++){
        for (int j=i;j<N;j++){
            if (i==j) continue;
            if (!grid2[i][j]) {
                succ2 = false;
                break;
            }
        }
        if (!succ2) break;
    }    
    
    if (succ2){
        printf("DA\n");
        return 0;
    }
    
    printf("NE\n");

    return 0;
}



