#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 100005
#define PMAX 18

using namespace std;

int N, M;
vector<int> graph[MAX];
vector<int> tree[MAX];
int depth[MAX];
int p[MAX][PMAX];

void make_tree(int curr){
    for (int next: graph[curr]){
        if (depth[next] == -1){
            depth[next] = depth[curr] + 1;
            p[next][0] = curr;
            make_tree(next);
        }
    }
    return;
}

int get_LCA(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j=0;diff;j++){
        if (diff % 2) u = p[u][j];
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

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N-1;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    memset(p, -1, sizeof(p));
    depth[1] = 0;
    make_tree(1);
    
    for (int j=0;j<=PMAX-1;j++){
        for (int i=1;i<=N;i++){
            if (p[i][j] != -1){
                p[i][j+1] = p[p[i][j]][j];
            }
        }
    }
    
    scanf("%d", &M);
    for (int x=0;x<M;x++){
        int r, u, v;
        scanf("%d %d %d", &r, &u, &v);
        int r_0 = r, u_0 = u, v_0 = v;
        int uv_LCA = get_LCA(u, v);
        u = u_0, v = v_0;
        int ur_LCA = get_LCA(u, r);
        u = u_0, r = r_0;
        int vr_LCA = get_LCA(v, r);
        v = v_0, r = r_0;
        int ans = uv_LCA;
        ans = depth[ans] > depth[ur_LCA] ? ans : ur_LCA;
        ans = depth[ans] > depth[vr_LCA] ? ans : vr_LCA;
        printf("%d\n", ans);
    }
    
    return 0;
}
