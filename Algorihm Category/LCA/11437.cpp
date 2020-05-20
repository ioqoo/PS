#include <iostream>
#include <vector>
#include <cstring>

const int NMAX = 50005;
const int PMAX = 18;
using namespace std;

int N, M;
int p[NMAX][PMAX];
int depth[NMAX];
vector<int> graph[NMAX];

void make_tree(int curr){
    for (int next: graph[curr]){
        if (depth[next] == -1){
            depth[next] = depth[curr] + 1;
            p[next][0] = curr;
            make_tree(next);
        }
    }
}

int get_lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i=0;diff;i++){
        if (diff%2){
            u = p[u][i];
        }
        diff /= 2;
    }
    if (u != v){
        for (int j=PMAX-1;j>=0;j--){
            if (p[u][j] != -1 && p[u][j] != p[v][j]){
                u = p[u][j];
                v = p[v][j];
            }
        }
        u = p[u][0];
    }
    return u;
}




int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int u, v;
    for (int i=0;i<N-1;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    memset(p, -1, sizeof(p));
    depth[1] = 0;
    make_tree(1);
    
    for (int j=0;j<PMAX;j++){
        for (int i=1;i<=N;i++){
            if (p[i][j] != -1){
                p[i][j+1] = p[p[i][j]][j];
            }
        }
    }
    
    scanf("%d", &M);
    int a, b;
    for (int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", get_lca(a, b));
    }
    
    

    return 0;
}



