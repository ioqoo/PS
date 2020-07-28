#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 105;

using namespace std;

int N, M;
char grid[MAX][MAX];
bool keys[26];
bool visited[MAX][MAX];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int document;

bool isin(int i, int j){
    if (0 <= i && i <= N+1 && 0 <= j && j <= M+1) return true;
    else return false;
}

int solve(){
    memset(keys, 0, sizeof(keys));
    memset(visited, 0, sizeof(visited));
    document = 0;
    
    cin >> N >> M;
    
    for (int i=0;i<=N+1;i++){
        for (int j=0;j<=M+1;j++){
            grid[i][j] = '.';
        }
    }
    string row;
    for (int i=1;i<=N;i++){
        cin >> row;
        for (int j=0;j<M;j++){
            grid[i][j+1] = row[j];
        }
    }
    string key;
    cin >> key;
    if (key != "0") {
        for (int i=0;i<key.size();i++){
            keys[key[i]-'a'] = true;
        }
    }
//    for (int i=0;i<26;i++){
//        cout << keys[i] << " ";
//    }
//    cout << endl;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            char curr = grid[i][j];
            if ('A' <= curr && curr <= 'Z'){
                if (keys[curr-'A']) grid[i][j] = '.';
            }
        }
    }
    
//    for (int i=0;i<=N+1;i++){
//        for (int j=0;j<=M+1;j++){
//            cout << grid[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
    
    
    queue<pii> Q;
    Q.push({0, 0});
    visited[0][0] = true;
    while(!Q.empty()){
        auto curr = Q.front(); Q.pop();
        int ci = curr.first, cj = curr.second;
        for (int d=0;d<4;d++){
            int ni = ci + di[d], nj = cj + dj[d];
            if (!isin(ni, nj)) continue;
            char next = grid[ni][nj];
            if (visited[ni][nj]) continue;
            if (next == '*') continue;
            if ('a' <= next && next <= 'z') {
                if (keys[next-'a']) {
                    grid[ni][nj] = '.';
                    visited[ni][nj] = true;
                    Q.push({ni, nj});
                }
                else{
                    keys[next-'a'] = true;
                    grid[ni][nj] = '.';
                    for (int i=1;i<=N;i++){
                        for (int j=1;j<=M;j++){
                            if (grid[i][j]-'A'+'a' == next){
                                grid[i][j] = '.';
                            }
                        }
                    }
                    while(!Q.empty()){
                        Q.pop();
                    }
                    memset(visited, 0, sizeof(visited));
                    Q.push({ni, nj});
                    visited[ni][nj] = true;
                    break;
                }
            }
            else if (next == '$'){
                document++;
                grid[ni][nj] = '.';
                Q.push({ni, nj});
                visited[ni][nj] = true;
            }
            else if (next == '.'){
                visited[ni][nj] = true;
                Q.push({ni, nj});
            }
        }
    }
    return document;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }

    return 0;
}



