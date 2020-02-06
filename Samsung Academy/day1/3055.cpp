#include <bits/stdc++.h>
#define MAX 55
#define pii pair<int, int>
#define INF 987654321

using namespace std;

int grid[MAX][MAX];
int route[MAX][MAX];
int water[MAX][MAX];
bool water_visited[MAX][MAX];
int water_dist[MAX][MAX];
bool route_visited[MAX][MAX];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int R, C;
pii S, D;

void W(){
    queue<pii> q;
    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++){
            if (grid[i][j] == 1){
                q.push(pii(i, j));
            }
        }
    }

    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int ci = p.first, cj = p.second;
        for (int d=0;d<4;d++){
            int ni = ci + di[d], nj = cj + dj[d];
            if (ni <= 0 || ni > R || nj <= 0 || nj > C) continue;
            if (water_visited[ni][nj]) continue;
            if (water[ni][nj] == -1){
                water[ni][nj] = 1;
                water_visited[ni][nj] = true;
                water_dist[ni][nj] = water_dist[ci][cj] + 1;
                q.push(pii(ni, nj));
            }
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;

    for (int i=1;i<=R;i++){
        string row;
        cin >> row;
        for (int j=0;j<row.size();j++){
            char curr = row[j];
            if (curr == '*'){
                grid[i][j+1] = 1;
                water[i][j+1] = 1;
            }
            else if (curr == 'X'){
                grid[i][j+1] = 2;
                water[i][j+1] = INF;
            }
            else if (curr == 'S'){
                grid[i][j+1] = 3;
                S = pii(i, j+1);
                water[i][j+1] = INF;
            }
            else if (curr == 'D'){
                grid[i][j+1] = 4;
                D = pii(i, j+1);
                water[i][j+1] = INF;
                water_dist[i][j+1] = INF;
                route[i][j+1] = INF;
            }
            else{
                water[i][j+1] = -1;
            }
        }
    }

    W();
//    for (int i=1;i<=R;i++){
//        for (int j=1;j<=C;j++){
//            cout << water_dist[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << endl;

    queue<pii> Q;
    Q.push(S);
    route_visited[S.first][S.second] = true;
    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        int ci = p.first, cj = p.second;
        for (int d=0;d<4;d++){
            int ni = ci + di[d], nj = cj + dj[d];
            if (ni <= 0 || ni > R || nj <= 0 || nj > C) continue;
            if (route_visited[ni][nj]) continue;
            if (route[ci][cj] + 1 >= water_dist[ni][nj] && water[ni][nj] != -1) continue;
            if (grid[ni][nj] == 0 || grid[ni][nj] == 4){
                route[ni][nj] = route[ci][cj] + 1;
                route_visited[ni][nj] = true;
                Q.push(pii(ni, nj));
            }
        }
    }
//
//    for (int i=1;i<=R;i++){
//        for (int j=1;j<=C;j++){
//            cout << route[i][j] << " ";
//        }
//        cout << endl;
//    }

    int ans = route[D.first][D.second];
    if (ans == INF) {
        cout << "KAKTUS";
    }
    else{
        cout << ans;
    }



    return 0;

}
