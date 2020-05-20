#include <iostream>
#include <string>
#include <cstring>
#include <queue>

#define MAX 1005
#define pii pair<int, int>

using namespace std;

int T, W, H;
int grid[MAX][MAX];
int Si, Sj;
string row;
bool visited[MAX][MAX];
int dist[MAX][MAX];
int dist_run[MAX][MAX];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T>0){
        T--;
        
        cin >> W >> H;
        memset(visited, 0, sizeof(visited));
        memset(dist, -1, sizeof(dist));
        memset(dist_run, 0, sizeof(dist_run));
        queue<pii> Q;
        
        for (int i=0;i<H;i++){
            cin >> row;
            for (int j=0;j<W;j++){
                char c = row[j];
                if (c == '#') grid[i][j] = 1;
                else if (c == '@') {
                    Si = i; Sj = j;
                }
                else if (c == '*') {
                    grid[i][j] = 2;
                    Q.push({i, j});
                    dist[i][j] = 0;
                    visited[i][j] = true;
                }
                else grid[i][j] = 0;
            }
        }
        
        while(!Q.empty()){
            auto p = Q.front();
            Q.pop();
            int ci = p.first, cj = p.second;
            for (int d=0;d<4;d++){
                int ni = ci + di[d], nj = cj + dj[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W || grid[ni][nj] == 1) continue;
                if (visited[ni][nj]) continue;                
                dist[ni][nj] = dist[ci][cj] + 1;
                Q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
        
//        for (int i=0;i<H;i++){
//            for (int j=0;j<W;j++){
//                cout << dist[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        
        
        memset(visited, 0, sizeof(visited));
        queue<pii> Q2;
        Q2.push({Si, Sj});
        visited[Si][Sj] = true;
        bool succ = false;
        int ans = -1;
        while(!Q2.empty()){
            auto p = Q2.front();
            int ci = p.first, cj = p.second;
            Q2.pop();
            for (int d=0;d<4;d++){
                int ni = ci + di[d], nj = cj + dj[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    succ = true;
                    ans = dist_run[ci][cj] + 1;
                    break;
                }
                if (grid[ni][nj] == 1) continue;
                if (visited[ni][nj]) continue;
                if (dist_run[ci][cj] + 1 >= dist[ni][nj] && dist[ni][nj] != -1) continue;
                dist_run[ni][nj] = dist_run[ci][cj] + 1;
                visited[ni][nj] = true;
                Q2.push({ni, nj});
            }
            if (succ) break;
        }
        if (!succ) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
        
    }
    
    return 0;
}


