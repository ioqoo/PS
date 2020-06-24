#include <bits/stdc++.h>

const int MAX = 1005;
using namespace std;

int N, M;
int grid[MAX][MAX];
bool chk[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%d", &grid[i][j]);
        }
    }
    
    for (int i=0;i<N;i++){
        int curr_maxval = -1, curr_maxpos = -1;
        for (int j=0;j<M;j++){
            if (grid[i][j] > curr_maxval) {
                curr_maxpos = j;
                curr_maxval = grid[i][j];
            }
        }
        chk[i][curr_maxpos] = true;
    }
    
    for (int j=0;j<M;j++){
        int curr_maxval = -1, curr_maxpos = -1;
        for (int i=0;i<N;i++){
            if (grid[i][j] > curr_maxval) {
                curr_maxpos = i;
                curr_maxval = grid[i][j];
            }
        }
        chk[curr_maxpos][j] = true;
    }
    
    int ans = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (!chk[i][j]) ans+=grid[i][j];
        }
    }
    
    printf("%d\n", ans);
    
    
    return 0;
}



