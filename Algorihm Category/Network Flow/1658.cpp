#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int INF = 987654321;
const int MAX = 1300;
const int S = 1202;
const int E = 1203;

using namespace std;

struct edge{
    int c, f, to;
    edge* dual;
    edge(): edge(0, -1){};
    edge(int c1, int to1){
        c = c1;
        f = 0;
        to = to1;
        dual = nullptr;
    }
    int spare(){
        return c-f;
    }
    void addflow(int flow){
        f += flow;
        dual->f -= flow;
    }
};

int N;
vector<edge*> grpah[MAX];
int level[MAX], chk[MAX];

bool bfs(){
    memset(level, -1, sizeof(level));
    level[S] = 0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        for (edge *e: graph[curr]){
            int next = e->to;
            if (level[next] == -1 && e->spare() > 0) {
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
        int next = graph[curr][i]->to;
        if (level[next] == level[curr] + 1 && graph[curr][i]->spare() > 0){
            int df = min(flow, dfs(next, dest, graph[curr][i]->spare());
            if (df > 0){
                graph[curr][i]->addflow(df);
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
    for (int i=0;i<M;i++){
        
    }

    return 0;
}



