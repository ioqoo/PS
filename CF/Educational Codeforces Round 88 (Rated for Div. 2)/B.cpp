#include <bits/stdc++.h>

using namespace std;

int grid[102][1002];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
//    scanf("%d", &t);
    cin >> t;
    while(t--){
        int n, m, x, y;
        string row;
        cin >> n >> m >> x >> y;
        memset(grid, 0, sizeof(grid));
        int zerocnt = 0;
        for (int i=0;i<n;i++){
            cin >> row;
            for (int j=0;j<m;j++){
                if (row[j] == '*') grid[i][j] = 1;
                else {
                    grid[i][j] = 0;
                    zerocnt++;
                }
            }
        }
        
        if (x*2 < y){
            printf("%d\n", zerocnt * x);
        }
        else{
            int ans = 0;
            for (int i=0;i<n;i++){
                int temp = 0;
                for (int j=0;j<m;){
                    if (grid[i][j] == 0){
                        if (j < m-1 && grid[i][j+1] == 0){
                            temp += y;
                            j += 2;
                        }
                        else {
                            temp += x;
                            j++;
                        }
                        continue;
                    }
                    j++;
                }
                ans += temp;
            }
            printf("%d\n", ans);
        }
        
    }

    return 0;
}



