#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const int MAX = 805;
const int INF = 1e9+7;

using namespace std;

int N, P;
vector<int> graph[MAX];
int pre[MAX];
int c[MAX][MAX], f[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &P);
    for (int i=1;i<=N;i++){ // 1 ~ 400 : in, 401 ~ 800 : out
        int out = i+400;
        graph[i].push_back(out);
        graph[out].push_back(i);
        c[i][out] = 1;
    }
    
    int a, b;
    for (int i=0;i<P;i++){
        scanf("%d %d", &a, &b);
        int aout = a+400, bout = b+400;
        graph[aout].push_back(b);
        graph[b].push_back(aout);
        graph[bout].push_back(a);
        graph[a].push_back(bout);
        c[aout][b] = 1;
        c[bout][a] = 1;
    }
    
    int total = 0, S = 401, E = 2;
    while(1){
        memset(pre, -1, sizeof(pre));
        queue<int> Q;
        Q.push(S);
        while(!Q.empty() && pre[E] == -1){
            int curr = Q.front();
            Q.pop();
            for (int next: graph[curr]){
                if (c[curr][next] - f[curr][next] > 0 && pre[next] == -1){
                    Q.push(next);
                    pre[next] = curr;
                    if (next == E) break;
                }
            }
        }
        if(pre[E] == -1) break;
        int flow = INF;
        for (int i=E;i!=S;i=pre[i]){
            flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
        }
        for (int i=E;i!=S;i=pre[i]){
            f[pre[i]][i] += flow;
            f[i][pre[i]] -= flow;
        }
        total += flow;
    }
    printf("%d\n", total);

    return 0;
}



