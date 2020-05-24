#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int PMAX = 18;
const int MAX = 100003;
#define pii pair<int, int>
using namespace std;

int N, M, Q;
int p[MAX];
int range[MAX];
map<int, int> cmap;
vector<pii> graph[MAX];
int depth[MAX];
int parent[MAX][PMAX];
int maxtemp[MAX][PMAX];

struct edge{
    int u, v, c;
};

struct cmp{
    bool operator () (const edge &a, const edge &b){
        return a.c > b.c;
    }
};

int find(int node){
    if (p[node] < 0) return node;
    return p[node] = find(p[node]);
}

bool merge(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return false;
    p[roota] += p[rootb]; // roota : new root
    p[rootb] = roota;
    return true;
}

void makedepth(int curr){
    for (auto P: graph[curr]){
        int next = P.first, weight = P.second;
        if (depth[next] != -1) continue;
        depth[next] = depth[curr] + 1;
        parent[next][0] = curr;
        maxtemp[next][0] = weight;
        makedepth(next);
    }
    return;
}

int getmaxtemp(int u, int v){
    int ret = -1;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i=0;diff;i++){
        if (diff%2) {
            ret = max(ret, maxtemp[u][i]);
            u = parent[u][i];
        }
        diff /= 2;
    }
    if (u!=v){
        for (int j=PMAX-1;j>=0;j--){
            if (parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                ret = max(ret, maxtemp[u][j]);
                ret = max(ret, maxtemp[v][j]);
                u = parent[u][j];
                v = parent[v][j];
            }
        }
        ret = max(ret, maxtemp[u][0]);
        ret = max(ret, maxtemp[v][0]);
        u = parent[u][0];
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    memset(p, -1, sizeof(p));
    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));
    memset(maxtemp, -1, sizeof(maxtemp));
    
    scanf("%d %d", &N, &M);
    int u, v, c;
    int cntc = 0;
    priority_queue<edge, vector<edge>, cmp> PQ;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &c);
        cmap[c] = cntc++;
        PQ.push({u, v, c});
    }
    
    while(!PQ.empty()){
        auto P = PQ.top(); PQ.pop();
        int curr_u = P.u, curr_v = P.v, curr_c = P.c;
        if (find(curr_u) != find(curr_v)){
            merge(curr_u, curr_v);
            range[cmap[curr_c]] = -p[find(curr_u)];
            graph[curr_u].push_back({curr_v, curr_c});
            graph[curr_v].push_back({curr_u, curr_c});
        }
    }
    
//    for (int i=1;i<=4;i++){
//        printf("%d\n", range[cmap[i]]);
//    }
    
    for (int i=1;i<=N;i++){
        if (depth[i] == -1){
            depth[i] = 0;
            makedepth(i);
        }
    }
    
    for (int j=0;j<PMAX-1;j++){
        for (int i=1;i<=N;i++){
            if (parent[i][j] != -1){
                parent[i][j+1] = parent[parent[i][j]][j];
                if (parent[i][j+1] != -1) maxtemp[i][j+1] = max(maxtemp[i][j], maxtemp[parent[i][j]][j]);
            }
        }
    }
    
//    for (int i=1;i<=4;i++){
//        for (int j=0;j<=2;j++){
//            printf("2^%d th parent of %d , maxtemp : %d\n", j, i, maxtemp[i][j]);
//        }
//    }
    
    scanf("%d", &Q);
    int x, y;
    for (int i=0;i<Q;i++){
        scanf("%d %d", &x, &y);
        if (find(x) != find(y)){
            printf("-1\n");
            continue;
        }
        int currmaxtemp = getmaxtemp(x, y);
        if (currmaxtemp == -1){
            printf("-1\n");
        }
        else{
            int currrange = range[cmap[currmaxtemp]];
            printf("%d %d\n", currmaxtemp, currrange);
        }
    }
    

    return 0;
}



