#include <iostream>
#include <vector>
#include <cstring>

const int MAX = 2505;

using namespace std;

int N, M;
int A[MAX], B[MAX];
int grid[51][51];
bool visited[MAX];
vector<int> graph[MAX];
int verti[51][51], hori[51][51];

bool dfs(int a){
    visited[a] = true;
    for (int b: graph[a]){
        if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d\n", &N, &M);
    char temp;
    for (int i=0;i<N;i++){
        for (int j=0;j<=M;j++){
            scanf("%1c", &temp);
            if (temp == '\n') break;
            grid[i][j] = temp=='*'?1:0;
        }
    }
    
    int vertinum = 0;
    for (int i=0;i<N;i++){
        int pre = 0;
        for (int j=0;j<M;j++){
            int curr = grid[i][j];
            if (pre == 0 && curr == 1) verti[i][j] = ++vertinum;
            else if (pre == 1 && curr == 1) verti[i][j] = verti[i][j-1];
            pre = curr;
        }
    }
    
    int horinum = 0;
    for (int j=0;j<M;j++){
        int pre = 0;
        for (int i=0;i<N;i++){
            int curr = grid[i][j];
            if (pre == 0 && curr == 1) hori[i][j] = ++horinum;
            else if (pre == 1 && curr == 1) hori[i][j] = hori[i-1][j];
            pre = curr;
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if(verti[i][j] && hori[i][j]){
                graph[verti[i][j]].push_back(hori[i][j]);
            }
        }
    }
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int ans = 0;
    for (int i=1;i<=vertinum;i++){
        if (A[i] == -1) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}



