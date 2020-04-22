#include <iostream>
#include <string>

#define MAX 22

using namespace std;

int R, C;
char grid[MAX][MAX];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
bool used[30];
int ans = 0;

void dfs(int a, int b, int cnt){
    ans = max(ans, cnt);
    
    for (int d=0;d<4;d++){
        int ni = a + di[d], nj = b + dj[d];
        if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
        if (used[grid[ni][nj]-'A']) continue;
        used[grid[ni][nj]-'A'] = true;
        dfs(ni, nj, cnt+1);
        used[grid[ni][nj]-'A'] = false;
    }
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;
    string row;
    for (int i=0;i<R;i++){
        cin >> row;
        for (int j=0;j<C;j++){
            grid[i][j] = row[j];
        }
    }
    used[grid[0][0]-'A'] = true;
    dfs(0, 0, 1);
    printf("%d\n", ans);
    
    

    return 0;
}



