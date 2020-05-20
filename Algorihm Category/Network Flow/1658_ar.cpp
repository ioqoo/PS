#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int INF = 987654321;
const int MAX = 1300;
const int S = 1201;
const int E = 1202;

using namespace std;

int M, N;
int c[MAX][MAX], f[MAX][MAX], level[MAX], chk[MAX];
vector<int> graph[MAX];

bool bfs(){
    memset(level, -1, sizeof(level));
    level[S] = 0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        for (int next: graph[curr]){
            if (level[next] == -1 && c[curr][next] - f[curr][next] > 0){
                level[next] = level[curr] + 1;
                Q.push(next);
            }
        }
    }
    
    return level[E] != -1;
}

int dfs(int curr, int dest, int flow){
    if (curr == dest) return flow;
    
    for (int &i = chk[curr]; i<graph[curr].size();i++){
        int next = graph[curr][i];
        if (level[next] == level[curr] + 1 && c[curr][next] - f[curr][next] > 0){
            int df = dfs(next, dest, min(c[curr][next] - f[curr][next], flow));
            if (df > 0){
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
    
    scanf("%d %d", &M, &N);
    for (int i=1;i<=M;i++){
        scanf("%d", &c[i+100][E]);
        graph[i+100].push_back(E);
        graph[E].push_back(i+100);
    }
    
    int A, B;
    for (int i=1;i<=N;i++){
        scanf("%d", &A);
        int v;
        for (int j=0;j<A;j++){
            scanf("%d", &v);
            v += 100;
            graph[i].push_back(v);
            graph[v].push_back(i);
            c[i][v] = INF;
            for (int k=1;k<i;k++){
                if (c[i][k] != 0) continue;
                if (c[k][v] != 0){
                    graph[i].push_back(k);
                    graph[k].push_back(i);
                    c[i][k] = INF;
                }
            }
        }
        scanf("%d", &B);
        graph[S].push_back(i);
        graph[i].push_back(S);
        c[S][i] = B;
    }
    
    int total = 0;
    while(bfs()){
        memset(chk, 0, sizeof(chk));
        while(1){
            int flow = dfs(S, E, INF);
            if (flow == 0) break;
            total += flow;
        }
    }
    printf("%d\n", total);
    

    return 0;
}



