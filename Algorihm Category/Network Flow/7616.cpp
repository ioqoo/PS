#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>

const int INF = 987654321;
const int MAX = 10005;

using namespace std;

struct edge{
    int to, f, c;
    edge* dual;
    edge(){
        to = -1;
        c = 0;
        dual = nullptr;
    }
    edge(int to, int c){
        this->to = to;
        this->c = c;
        this->f = 0;
        dual = nullptr;
    }
    int spare(){
        return c - f;
    }
    void addflow(int f){
        this->f += f;
        dual->f -= f;
    }
};

int K, N;
vector<edge*> graph[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int T = 0;
    while(++T){
        scanf("%d %d\n", &K, &N);
        if (K==0 && N==0) break;
        printf("Case %d:\n", T);
        
        for (int i=1;i<=2*N;i++){
            graph[i].clear();
        }
        
        for (int i=1;i<=N;i++){ // 1, 3, 5 : in, 2, 4, 6 : out
            if (i==1 || i==2) continue;
            int in = i*2-1, out = in+1;
            edge *e1 = new edge(out, 1), *e2 = new edge(in, 0);
            e1->dual = e2, e2->dual = e1;
            graph[in].push_back(e1);
            graph[out].push_back(e2);
        }
        
        char temp;
        int b;
        for (int i=1;i<=N;i++){
            int aout = i*2;
            while(1){
                scanf("%d%c", &b, &temp);
                int bin = b*2-1;
                edge *e1 = new edge(bin, 1), *e2 = new edge(aout, 0);
                e1->dual = e2, e2->dual = e1;
                graph[aout].push_back(e1);
                graph[bin].push_back(e2);
                if (temp == '\n') break;
            }
        }
        int total = 0, S = 2, E = 3;
        while(1){
            int pre[MAX];
            memset(pre, -1, sizeof(pre));
            edge* path[MAX] = {0};
            queue<int> Q;
            Q.push(S);
            while(!Q.empty() && pre[E] == -1){
                int curr = Q.front(); Q.pop();
                for (edge *p: graph[curr]){
                    int next = p->to;
                    if (p->spare() > 0 && pre[next] == -1){
                        Q.push(next);
                        pre[next] = curr;
                        path[next] = p;
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
            if (total == K) break;
        }
        
        if (total < K){
            printf("Impossible\n\n");
            continue;
        }
        
        while(K--){
            int pre[MAX];
            memset(pre, -1, sizeof(pre));
            edge* path[MAX] = {0};
//            set<int> Set;
            vector<int> ans;
            
            queue<int> Q;
            Q.push(S);
            while(!Q.empty() && pre[E] == -1){
                int curr = Q.front(); Q.pop();
                for (edge *p: graph[curr]){
                    int next = p->to;
                    if (p->f == 1 && pre[next] == -1){
                        Q.push(next);
                        pre[next] = curr;
                        path[next] = p;
                        if (next == E) break;
                    }
                }
            }
            if (pre[E] == -1) break;
            
            for (int i=E;i!=S;i=pre[i]){
                if (i%2) ans.push_back((i+1)/2);                
                path[i]->addflow(-1);
            }
            ans.push_back(1);
            
            for (auto it=ans.rbegin();it!=ans.rend();it++){
                printf("%d ", *it);
            }
            printf("\n");
        }
        printf("\n");
        
    }

    return 0;
}



