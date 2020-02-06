#include <bits/stdc++.h>
#define MAX 53
#define INF 1000001
#define ll long long
#define pii pair<int, int>

using namespace std;

int N;
int grid[MAX][MAX];
int disc[MAX][MAX];
int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[MAX][MAX];
vector<pii> houses;
vector<int> H;
int start_i, start_j;

void debug(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << disc[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check(){
    for (auto p: houses){
        if (!visited[p.first][p.second]) return false;
    }
    return true;
}

void make_disc(int m, int M){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (grid[i][j] < m || grid[i][j] > M){
                disc[i][j] = -1;
            }
            else{
                disc[i][j] = grid[i][j];
            }
        }
    }
}

void BFS(int x, int y){
    if (disc[x][y] == -1) return;
    queue<pii> q;
    q.push(pii(x, y));
    visited[x][y] = true;

    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int ci = p.first, cj = p.second;
        for (int d=0;d<8;d++){
            int ni = ci + di[d], nj = cj + dj[d];
            if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
            if (visited[ni][nj]) continue;
            if (disc[ni][nj] == -1) continue;
            visited[ni][nj] = true;
            q.push(pii(ni, nj));
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i=0;i<N;i++){
        string row;
        cin >> row;
        for (int j=0;j<N;j++){
            if (row[j] == 'K') {
                houses.push_back(pii(i, j));
            }
            else if (row[j] == 'P'){
                houses.push_back(pii(i, j));
                start_i = i;
                start_j = j;
            }
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            int temp;
            cin >> temp;
            grid[i][j] = temp;
            H.push_back(temp);
        }
    }

    sort(H.begin(), H.end());
    int H_size = H.size();

    int l = 0, r = 0;
    int ans = INF;;

    while(l < H.size() || r < H.size()){
        memset(visited, 0, sizeof(visited));
        make_disc(H[l], H[r]);
        BFS(start_i, start_j);
        if (!check()){
            if (r == H.size() - 1){
                break;
            }
            r++;
        }
        else{
            ans = min(ans, H[r] - H[l]);
            l++;
        }
    }

    cout << ans << endl;


//
//    int house_min = INF, house_max = 0;
//
//    for (auto p: houses){
//        int curr = grid[p.first][p.second];
//        house_min = min(curr, house_min);
//        house_max = max(curr, house_max);
//    }
//
//
//
//    int l = 0, r = house_min+1, mid = (l+r) / 2;
//
//    while(l+1 < r){
//        memset(visited, 0, sizeof(visited));
//        make_disc(mid, house_max);
//        cout << "min : " << mid << endl;
//        debug();
//        BFS(start_i, start_j);
//        if (check()) {
//            l = mid;
//        }
//        else{
//            r = mid;
//        }
//        mid = (l+r) / 2;
//
//    }
//
//    int ans_min = mid;
//
//    l = house_max-1, r = INF, mid = (l+r) / 2;
//
////    cout << endl;
//
//    while(l+1 < r){
//        memset(visited, 0, sizeof(visited));
//        make_disc(ans_min, mid);
//        BFS(start_i, start_j);
//        cout << "max : " << mid << endl;
//        debug();
//        if (check()){
//            r = mid;
//        }
//        else{
//            l = mid;
//        }
//        mid = (l+r) / 2;
//
//    }
//
//    int ans_max = mid + 1;
//
//    cout << ans_max << " " <<ans_min << endl;
//
//    cout << ans_max - ans_min;



    return 0;
}
