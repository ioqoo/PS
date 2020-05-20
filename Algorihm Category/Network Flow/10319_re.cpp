#include <bits/stdc++.h>

const int MAX = 1100*110;
const int INF = 987654321;
const int SOURCE = 110000;
const int SINK = 110001;

using namespace std;

struct edge{
    int to, c, f;
    edge* dual;
    edge(): edge(-1, 0){};
    edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){};
    int spare(){
        return c-f;
    }
    void addflow(int flow){
        f += flow;
        dual->f -= flow;
    }
};

int T, N, I, G, S, M, R;
int u, v, p, t;
vector<edge*> graph[MAX];

void addedge(int u, int v, int cap){ // u->v
    edge *e1 = new edge(v, cap);
    edge *e2 = new edge(u, 0);
    e1->dual = e2; e2->dual = e1;
    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        for(int i=0;i<MAX;i++){
            graph[i].clear();
        }
        scanf("%d", &N);
        scanf("%d %d %d", &I, &G, &S);
        scanf("%d", &M);
        for(int i=0;i<M;i++){
            scanf("%d", &u);
            for (int j=0;j<=S;j++){
                addedge(u*101 + j, SINK, INF);
            }
        }
        scanf("%d", &R);
        for (int i=0;i<R;i++){
            scanf("%d %d %d %d", &u, &v, &p, &t);
            for (int j=0;j+t<=S;j++){
                addedge(u*101 + j, v*101 + j+t, p);
            }
        }
        for (int i=1;i<=N;i++){
            for (int j=0;j<S;j++){
                addedge(i*101+j, i*101+j+1, INF);
            }
        }
        
        addedge(SOURCE, I*101, G);
        
        int total = 0;
        while(1){
            int pre[MAX];
            edge* path[MAX];
            memset(pre, -1, sizeof(pre));
            queue<int> Q;
            Q.push(SOURCE);
            while(!Q.empty() && pre[SINK] == -1){
                int curr = Q.front(); Q.pop();
                for (edge *e: graph[curr]){
                    int next = e->to;
                    if (pre[next] == -1 && e->spare() > 0){
                        pre[next] = curr;
                        Q.push(next);
                        path[next] = e;
                        if (next == SINK) break;
                    }
                }
            }
            if (pre[SINK] == -1) break;
            int flow = INF;
            for (int i=SINK;i!=SOURCE;i=pre[i]){
                flow = min(flow, path[i]->spare());
            }
            for (int i=SINK;i!=SOURCE;i=pre[i]){
                path[i]->addflow(flow);
            }
            total += flow;
            if (total >= 100) break;
        }
        printf("%d\n", total);
        
    }

    return 0;
}



