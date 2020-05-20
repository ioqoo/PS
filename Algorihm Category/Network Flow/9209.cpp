#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

const int S = 180003;
const int E = 180004;
const int MAX = 180008;
const int INF = 987654321;

using namespace std;

struct edge{
    int to, c, f;
    edge* dual;
    edge(): edge(-1, 0){}
    edge(int to, int c): to(to), c(c), f(0), dual(nullptr){}
    int spare() {
        return c - f;
    }
    void addflow(int flow){
        f += flow;
        dual->f -= flow;
    }
};


int N, M;
int grid[303][303];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
vector<edge*> graph[MAX];


int convert(int i, int j) {
    return i*M+j;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%d", &grid[i][j]);
        }
    }
//    for (int i=0;i<N;i++){
//        for (int j=0;j<M;j++){
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    
    for (int i=0;i<N;i++){ // 0, 2, 4, .. : in, 1, 3, 5 : out
        for (int j=0;j<M;j++){
            if (grid[i][j] == 0) continue;
            int curr = convert(i, j);
            int val = grid[i][j];
            int currin = curr*2, currout = currin+1;
//            printf("curr : %d / currin : %d / currout : %d\n", curr, currin, currout);
            edge *e1, *e2;
            if (i==0 || i==N-1 || j==0 || j==M-1){
                e1 = new edge(currin, INF), e2 = new edge(S, 0);
                e1->dual = e2, e2->dual = e1;
                graph[S].push_back(e1);
                graph[currin].push_back(e2);
            }
            e1 = new edge(currout, val), e2 = new edge(currin, 0);
            e1->dual = e2, e2->dual = e1;
            graph[currin].push_back(e1);
            graph[currout].push_back(e2);
            
            for (int d=0;d<4;d++){
                int ni = i + di[d], nj = j + dj[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                if (grid[ni][nj] == 0) continue;
                int next = convert(ni, nj);
                int nextin = next*2;
                e1 = new edge(nextin, INF), e2 = new edge(currout, 0);
                e1->dual = e2, e2->dual = e1;
                graph[currout].push_back(e1);
                graph[nextin].push_back(e2);
            }
        }
    }
    
    int ci, cj;
    scanf("%d %d", &ci, &cj);
    int castle = convert(ci, cj);
    int castleout = castle*2+1;
    edge *e1 = new edge(E, INF), *e2 = new edge(castleout, 0);
    e1->dual = e2, e2->dual = e1;
    graph[castleout].push_back(e1);
    graph[E].push_back(e2);
    
//    for (int i=0;i<N;i++){
//        for (int j=0;j<M;j++){
//            int curr = convert(i, j);
//            printf("curr : %d\n", curr);
//            for (edge *e: graph[curr*2+1]){
//                printf("%d ", (e->to)/2);
//            }
//            printf("\n");
//        }
//    }
    
    int total = 0;
    while(1){
        int pre[MAX];
        memset(pre, -1, sizeof(pre));
        edge* path[MAX] = {0,};
        queue<int> Q;
        Q.push(S);
        while(!Q.empty() && pre[E] == -1){
            int curr = Q.front(); Q.pop();
            for (edge *e: graph[curr]){
                int next = e-> to;
                if (e->spare() > 0 && pre[next] == -1){
                    Q.push(next);
                    pre[next] = curr;
                    path[next] = e;
                    if (next == E) break;
                }
            }
        }
        if (pre[E] == -1) break;
        
        int flow = INF;
        for (int i=E;i!=S;i=pre[i]){
            flow = min(flow, path[i]->spare());
        }
        for (int i=E;i!=S;i=pre[i]){
            path[i]->addflow(flow);
        }
        total += flow;
    }
    printf("%d\n", total);
    

    return 0;
}



