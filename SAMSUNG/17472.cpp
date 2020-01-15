// 최소 비용 + 모두 연결 -> MST

#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF 987654321
#define MAX 10

using namespace std;

int N, M;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int p[10];
int ans;
vector<pii> graph[10];

bool cmp(pair<int,pii> a, pair<int,pii> b)
{
    return a.first > b.first;
}

priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int, pii>> > PQ;

int find(int node)
{
    if (p[node] == -1) return node;
    p[node] = find(p[node]);
    return p[node];
}

bool merge(int a, int b)
{
    int root1 = find(a);
    int root2 = find(b);
    if (root1 == root2) return false;
    p[root1] = root2;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    memset(p, -1, sizeof(p));
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%d", &grid[i][j]);
        }
    }

    int island = 0;
    queue<pii> q;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            int curr = grid[i][j];
            if (curr != 0 && !visited[i][j]){
                island++;
                grid[i][j] = island;
                q.push(pii(i, j));
                visited[i][j] = true;
                while(!q.empty()){
                    pii p = q.front();
                    q.pop();
                    int ci = p.first, cj = p.second;
                    for (int d=0;d<4;d++){
                        int ni = ci + dx[d], nj = cj + dy[d];
                        if (ni < 0 || ni >= N || nj < 0 || nj >= M || visited[ni][nj] || grid[ni][nj] == 0){
                            continue;
                        }
                        grid[ni][nj] = island;
                        q.push(pii(ni, nj));
                        visited[ni][nj] = true;
                    }
                }
            }
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            int curr = grid[i][j];
            if (curr != 0){
                for (int d=0;d<4;d++){
                    int ni = i + dx[d], nj = j + dy[d];
                    //if (ni < 0 || N <= ni || nj < 0 || M <= nj) continue;
                    int next = grid[ni][nj];
                    if (next == 0){
                        int len = 0;
                        while(true){
                            len++;
                            ni += dx[d], nj += dy[d];
                            if (ni < 0 || N <= ni || nj < 0 || M <= nj) break;

                            int last = grid[ni][nj];
                            if (last != 0){
                                if (len < 2) break;
                                graph[curr].push_back(pii(len, last));
                                PQ.push(make_pair(len, pii(curr, last)));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
//    for (int i=0;i<N;i++){
//        for (int j=0;j<M;j++){
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//
//    for (int i=0;i<N;i++){
//        for (auto j: graph[i]){
//            printf("%d %d %d\n", i, j.second, j.first);
//        }
//    }


    int edge_cnt = 0;
    while(!PQ.empty()){
        pair<int, pii> P = PQ.top();
        PQ.pop();
        int len = P.first, u = P.second.first, v = P.second.second;
        if (merge(u, v)){
            ans += len;
            edge_cnt++;
        }
        if (edge_cnt == island - 1){
            printf("%d\n", ans);
            return 0;
        }

    }
    printf("-1");


}
