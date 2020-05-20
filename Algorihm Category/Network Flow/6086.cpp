#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

const int MAX = 805;
const int INF = 1000000007;

using namespace std;

struct edge{
    int to, f, c;
    edge* dual;
    edge(){
        to = -1;
        c = 0;
    }
    edge(int to, int c){
        this->to = to;
        this->c = c;
        this->f = 0;
        this->dual = nullptr;
    }
    int spare(){
        return c-f;
    }
    void addflow(int f){
        this->f += f;
        dual->f -= f;
    }
};

int N, P;
vector<edge*> graph[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &P);
    for (int i=1;i<=N;i++){ // 1, 3, 5... : in, 2, 4, 6... : out
        int in = i*2-1, out = in+1;
        edge *e1 = new edge(out, 1), *e2 = new edge(in, 0);
        e1->dual = e2, e2->dual = e1;
        graph[in].push_back(e1);
        graph[out].push_back(e2);
    }
    
    int a, b;
    for (int i=0;i<P;i++){
        scanf("%d %d", &a, &b);
        int ain = a*2-1, aout = a*2, bin = b*2-1, bout = b*2;
        edge *e1 = new edge(bin, 1), *e2 = new edge(ain, 1);
        edge *e3 = new edge(bout, 0), *e4 = new edge(aout, 0);
        e1->dual = e4, e4->dual = e1;
        e3->dual = e2, e2->dual = e3;
        graph[aout].push_back(e1);
        graph[bout].push_back(e2);
        graph[ain].push_back(e3);
        graph[bin].push_back(e4);
        
    }
    
    int total = 0, S = 2, E = 3;
    while(1){
        int pre[MAX];
        fill(pre, pre+MAX, -1);
        edge* path[MAX] = {0};
        queue<int> Q;
        Q.push(S);
        while(!Q.empty() && pre[E] == -1){
            int curr = Q.front();
            Q.pop();
            for (edge *e: graph[curr]){
                int next = e->to;
                if (e->spare() > 0 && pre[next] == -1){
                    Q.push(next);
                    pre[next] = curr;
                    path[next] = e; // 'curr -> next' path is in path[next]
                    if (next == E) break;
                }
            }
        }
        if (pre[E] == -1) break; // no more shortest path
        
        int flow = INF;
        for (int i=E;i!=S;i=pre[i]){
            flow = min(flow, path[i]->spare()); // find minimum residual
        }
        for (int i=E;i!=S;i=pre[i]){
            path[i]->addflow(flow);
        }
        total += flow;
    }
    
    printf("%d\n", total);

    return 0;
}



