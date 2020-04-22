#include <iostream>
#include <cstring>
#define MAX 103

using namespace std;

int T, N;
int grid[MAX][MAX];
bool visited[MAX];
int ans_row, ans_col, trace;


int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    #endif
    
    scanf("%d", &T);
    for (int t=1;t<=T;t++){
        scanf("%d", &N);
        ans_row = 0, ans_col = 0, trace = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                scanf("%d", &grid[i][j]);
                if (i==j) trace += grid[i][j];
            }
        }
        
        for (int i=0;i<N;i++){
            memset(visited, 0, sizeof(visited));
            for (int j=0;j<N;j++){
                if (visited[grid[i][j]]) {
                    ans_row++;
                    break;
                }
                visited[grid[i][j]] = true;
            }
        }
        for (int j=0;j<N;j++){
            memset(visited, 0, sizeof(visited));
            for (int i=0;i<N;i++){
                if (visited[grid[i][j]]){
                    ans_col++;
                    break;
                }
                visited[grid[i][j]] = true;
            }
        }
        
        printf("Case #%d: %d %d %d\n", t, trace, ans_row, ans_col);
    }

    return 0;
}

