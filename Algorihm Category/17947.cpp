#include <bits/stdc++.h>
#define all(vt) vt.begin(),vt.end()

const int MAX = 1005;
using namespace std;

int N;
int grid[MAX][MAX];
int psum[MAX][MAX];

struct co{
    int x, y;
};

vector<co> cow;
vector<int> xco, yco;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        cow.push_back({x, y});
        xco.push_back(x);
        yco.push_back(y);
    }
    
    sort(all(xco));
    sort(all(yco));
    xco.erase(unique(all(xco)), xco.end());
    yco.erase(unique(all(yco)), yco.end());
    for (int i=0;i<N;i++){
        cow[i].x = lower_bound(all(xco), cow[i].x) - xco.begin();
        cow[i].y = lower_bound(all(yco), cow[i].y) - yco.begin();
    }
    for (int i=0;i<N;i++){
        grid[cow[i].x][cow[i].y] = 1;
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + grid[i-1][j-1];
        }
    }
    // psum[i][j] : (0,0) ~ (i-1, j-1)
    
    
    int ans = 0x3f3f3f3f;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            int lt = psum[i][j];
            int rt = psum[i][N] - lt;
            int lb = psum[N][j] - lt;
            int rb = psum[N][N] - psum[i][N] - psum[N][j] + lt;
            int curr_max = max(max(lt, rt), max(lb, rb));
            ans = min(ans, curr_max);
        }
    }
    printf("%d\n", ans);

    return 0;
}



