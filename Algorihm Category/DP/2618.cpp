#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 1005

using namespace std;

int N, W;
pii task[MAX];
int dp[MAX][MAX];
int ans[MAX][MAX];

int dist(pii A, pii B){
    return abs(A.first - B.first) + abs(A.second - B.second);
}

int solve(int a, int b){
    int curr_num = max(a, b) + 1;
    if (curr_num == W+2) return 0;
    
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    
    int X = solve(curr_num, b) + dist(task[a], task[curr_num]);
    int Y = solve(a, curr_num) + dist(task[b], task[curr_num]);
    if (X < Y) ans[a][b] = 1;
    else ans[a][b] = 2;
    
    return ret = min(X, Y);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &W);
    
    memset(dp, -1, sizeof(dp));
    
    task[0] = pii(1, 1);
    task[1] = pii(N, N);
    int x, y;
    for (int i=2;i<=W+1;i++){
        scanf("%d %d", &x, &y);
        task[i] = pii(x, y);
    }
    
    printf("%d\n", solve(0, 1));
    
    for (int x=0, y=1; max(x, y)+1 <= W+1; ){
        printf("%d\n", ans[x][y]);
        if (ans[x][y] == 1) x = max(x,y) + 1;
        else y = max(x, y) + 1;
    }
    
    return 0;
}
