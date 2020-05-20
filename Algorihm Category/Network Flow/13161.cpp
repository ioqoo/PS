#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

const int INF = 987654321;
const int MAX = 505;
const int S = 502;
const int E = 503;

using namespace std;

int N;
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX];
int level[MAX], chk[MAX];

bool bfs(){
    memset(level, -1, sizeof(level));
    level[S] = 0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        for (int next: graph[curr]){
            if (c[curr][next] - f[curr][next] > 0 && level[next] == -1){
                level[next] = level[curr] + 1;
                Q.push(next);
            }
        }
    }
    return level[E] != -1;
}

int dfs(int curr, int dest, int flow){
    if (curr == dest) return flow;
    for (int &i = chk[curr];i<graph[curr].size();i++){
        int next = graph[curr][i];
        if (level[next] == level[curr] + 1 && c[curr][next] - f[curr][next] > 0){
            int df = dfs(next, dest, min(c[curr][next] - f[curr][next], flow));
            if (df > 0) {
                f[curr][next] += df;
                f[next][curr] -= df;
                return df;
            }
        }
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int party;
        scanf("%d", &party);
        if (party == 1) {
            graph[S].push_back(i);
            graph[i].push_back(S);
            c[S][i] = INF;
        }
        else if (party == 2){
            graph[i].push_back(E);
            graph[E].push_back(i);
            c[i][E] = INF;
        }
    }
    
    int temp;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%d", &temp);
            if (i==j) continue;
            graph[i].push_back(j);
            c[i][j] = temp;
        }
    }
    
    int total = 0;
    while(bfs()){
        memset(chk, 0, sizeof(chk));
        while(1){
            int flow = dfs(S, E, INF);
            if(flow == 0) break;
            total += flow;
        }
    }
    printf("%d\n", total);
    
    bool visited[MAX] = {0,};
    visited[S] = true;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        for (int next: graph[curr]){
            if (c[curr][next] - f[curr][next] > 0 && !visited[next]){
                visited[next] = true;
                Q.push(next);
            }
        }
    }
    
    for (int i=0;i<N;i++){
        if (visited[i]) printf("%d ", i+1);
    }
    printf("\n");
    for (int i=0;i<N;i++){
        if (!visited[i]) printf("%d ", i+1);
    }
    printf("\n");

    return 0;
}



