#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

int N, M;
int grid[53][53];
bool visited[53][53];
bool goodstart[53][53];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        memset(grid, 0, sizeof(grid));
        memset(visited, 0, sizeof(visited));
        memset(goodstart, 0, sizeof(goodstart));
        vector<pii> good, bad;
        cin >> N >> M;
        int gcnt = 0, bcnt = 0;
        string row;
        for (int i=0;i<N;i++){
            cin >> row;
            for (int j=0;j<M;j++){
                if (row[j] == '.'){
                    grid[i][j] = 1;
                }
                else if (row[j] == 'G'){
                    good.push_back({i, j});
                    gcnt++;
                    grid[i][j] = 2;
                }
                else if (row[j] == 'B'){
                    bad.push_back({i, j});
                    bcnt++;
                    grid[i][j] = 3;
                }
            }
        }
        if (gcnt == 0) {
            cout << "Yes\n";
            continue;
        }
        
        bool succ = true;
        for (auto p: bad){
            int ci = p.first, cj = p.second;
            for (int d=0;d<4;d++){
                int ni = ci + di[d], nj = cj + dj[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                if (grid[ni][nj] == 2){ // good
                    cout << "No\n";
                    succ = false;
                    break;
                }
                if (ni == N-1 && nj == M-1){ // dest
                    cout << "No\n";
                    succ = false;
                    break;
                }
                int curr = grid[ni][nj];
                if (curr == 1){
                    grid[ni][nj] = 0;
                }
            }
            if (!succ){
                break;
            }
        }
        if (!succ) continue;
        
        bool totalsucc = true;
        for (auto P=good.rbegin();P!=good.rend();P++){
            auto pp = *P;
            queue<pii> Q;
            Q.push({pp.first, pp.second});
            memset(visited, 0, sizeof(visited));
            visited[pp.first][pp.second] = true;
            bool flag = false;
            while(!Q.empty()){
                auto p = Q.front(); Q.pop();
                int ci = p.first, cj = p.second;
                for (int d=0;d<4;d++){
                    int ni = ci + di[d], nj = cj + dj[d];
                    if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                    if (goodstart[ni][nj]) {
                        goodstart[pp.first][pp.second] = true;
                        flag = true;
                        break;
                    }
                    if (grid[ni][nj] == 0) continue;
                    if (visited[ni][nj]) continue;
                    if (ni == N-1 && nj == M-1){
                        goodstart[pp.first][pp.second] = true;
                        flag = true;
                        break;
                    }
                    visited[ni][nj] = true;
                    Q.push({ni, nj});
                }
                if (flag) break;
            }
            if (!flag){
                totalsucc = false;
                break;
            }
        }
        if (totalsucc){
            cout << "Yes\n";            
        }
        else {
            cout << "No\n";
        }
        
//        
//        
//        bool flag = false;
//        while(!Q.empty()){
//            auto p = Q.front(); Q.pop();
//            int ci = p.first, cj = p.second;
//            for (int d=0;d<4;d++){
//                int ni = ci + di[d], nj = cj + dj[d];
//                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
//                if (grid[ni][nj] == 0) continue;
//                if (visited[ni][nj]) continue;
//                if (ni == N-1 && nj == M-1){
//                    flag = true;
//                    break;
//                }
//                visited[ni][nj] = true;
//                Q.push({ni, nj});
//            }
//            if (flag) break;
//        }
//        if (flag) {
//            cout << "Yes\n";
//        }
//        else {
//            cout << "No\n";
//        }
    }
    

    return 0;
}



