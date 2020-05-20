#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define pii pair<int, int>
//const int INF = 0x3f3f3f3f;
const int NMAX = 100005;
const int EMAX = 200005;
const int PMAX = 18;

using namespace std;

struct edge{
    int num, u, v, w;
};

struct cmp{
    bool operator() (edge a, edge b){
        return a.w > b.w;
    }
};

int N, M;
edge edgearr[EMAX];
vector<pii> graph[NMAX];
vector<pii> LCAtree[NMAX];
// *****mst*****
bool ismstedge[EMAX]; // true : #i edge was used for mst
int ufp[NMAX]; // union-find root
priority_queue<edge, vector<edge>, cmp> edgePQ;
priority_queue<edge, vector<edge>, cmp> nonmstPQ;
ll mst_val;
int mst_edgecnt;
bool mst_succ;
// *****LCA*****
int p[NMAX][PMAX]; // LCA parent parse table
int depth[NMAX]; // LCA depth table
// maxw[i][j] = largest weight between (node i) ~ (node i's 2^jth parent)
int maxw[NMAX][PMAX];

ll ans[EMAX];


int find(int node){
    if (ufp[node] == -1) return node;
    return ufp[node] = find(ufp[node]);
}

bool merge(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return false;
    ufp[roota] = rootb;
    return true;
}

void make_tree(int curr){
    for (auto pp: LCAtree[curr]){
        int next = pp.first, weight = pp.second;
        if (depth[next] == -1){
            depth[next] = depth[curr] + 1;
            p[next][0] = curr;
            maxw[next][0] = weight;
            make_tree(next);
        }
    }
}

int getmax(int u, int v){
    int ret = -1;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i=0;diff;i++){
        if (diff%2) {
            ret = max(ret, maxw[u][i]);
            u = p[u][i];
        }
        diff /= 2;
    }
    if (u!=v){
        for (int i=PMAX-1;i>=0;i--){
            if (p[u][i] != -1 && p[u][i] != p[v][i]){
                ret = max(ret, maxw[u][i]);
                ret = max(ret, maxw[v][i]);
                u = p[u][i];
                v = p[v][i];
            }
        }
        ret = max(ret, maxw[u][0]);
        ret = max(ret, maxw[v][0]);
        u = p[u][0];
    }
    return ret;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    scanf("%d %d", &N, &M);
    int u, v, w;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
        edgearr[i] = {i, u, v, w};
        edgePQ.push(edgearr[i]);
    }
    
    memset(ufp, -1, sizeof(ufp));
    while(!edgePQ.empty()){
        auto E = edgePQ.top();
        edgePQ.pop();
        if (merge(E.u, E.v)) {
            LCAtree[E.u].push_back(pii(E.v, E.w));
            LCAtree[E.v].push_back(pii(E.u, E.w));
            ismstedge[E.num] = true;
            mst_val += E.w;
            mst_edgecnt++;
        }
        else{
            nonmstPQ.push(E);
        }
    }
    
    if (mst_edgecnt != N-1) mst_succ = false;
    else mst_succ = true;
    if (!mst_succ){
        for (int i=0;i<M;i++){
            printf("-1\n");
        }
        return 0;
    }
        
    memset(p, -1, sizeof(p));
    memset(depth, -1, sizeof(depth));
    memset(maxw, -1, sizeof(maxw));
    depth[1] = 0;
    make_tree(1);
    
    for (int j=0;j<PMAX-1;j++){
        for (int i=1;i<=N;i++){
            if (p[i][j] != -1){
                p[i][j+1] = p[p[i][j]][j];
                if (p[i][j+1] != -1) maxw[i][j+1] = max(maxw[i][j], maxw[p[i][j]][j]);
            }
        }
    }
    
//    for (int i=1;i<=N;i++){
//        printf("***node %d***\n", i);
//        for (int j=0;j<=2;j++){
//            printf("max weight to 2^%d th parent node: %d\n", j, maxw[i][j]);
//        }
//    }
    
    while(!nonmstPQ.empty()){
        auto E = nonmstPQ.top();
        nonmstPQ.pop();
        int maxweight = getmax(E.u, E.v);
//        printf("u: %d , v: %d , maxweight between u~v : %d\n", E.u, E.v, maxweight);
        if (maxweight == -1){
            ans[E.num] = -1;
        }
        else {
            ans[E.num] = mst_val - maxweight + E.w;
        }
    }
    
    for (int i=0;i<M;i++){
        if (!ismstedge[i]) printf("%lld\n", mst_val);
        else printf("%lld\n", ans[i]);
    }
    

    return 0;
}



