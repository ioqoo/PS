#include <bits/stdc++.h>

#define pii pair<int, int>
const int INF = 1e9+7;
const int MAX = 303;
using namespace std;

int N, M;
int c[MAX][MAX], f[MAX][MAX];
vector<int> graph[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &M);
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        for (int i=0;i<MAX;i++){
            graph[i].clear();
        }
        int u, v, w;
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            c[u][v] = w;
        }
        
        int totalf = 0;
        while(1){
            int pre[MAX];
            memset(pre, -1, sizeof(pre));
            queue<int> Q;
            Q.push(1);
            while(!Q.empty() && pre[N] == -1){
                int curr = Q.front(); Q.pop();
                for (int next: graph[curr]){
                    if (c[curr][next] - f[curr][next] > 0 && pre[next] == -1){
                        Q.push(next);
                        pre[next] = curr;
                        if (next = N) break;
                    }
                }
            }
            if (pre[N] == -1) break;
            
            int flow = INF;
            for (int i=N;i!=1;i=pre[i]){
                flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
            }
            for (int i=N;i!=1;i=pre[i]){
                f[pre[i]][i] += flow;
                f[i][pre[i]] -= flow;
            }
            totalf += flow;
        }
        printf("%d\n", totalf);
        
        vector<pii> cand;
        for (int curr=1;curr<=N;curr++){
            for (int next: graph[curr]){
                if (c[curr][next] != 0 && c[curr][next] == f[curr][next]){
                    cand.push_back({curr, next});
                }
            }
        }
        
        int ans = 0;
        for (auto p: cand){
            int u = p.first, v = p.second;
//            printf("%d %d\n", u, v);
            c[u][v]--;
            int pre[MAX];
            memset(pre, -1, sizeof(pre));
            queue<int> Q;
            Q.push(u);
            while(!Q.empty()){
                int curr = Q.front(); Q.pop();
                for (int next: graph[curr]){
                    if (c[curr][next] != 0 && c[curr][next] - f[curr][next] > 0 && pre[next] == -1){
                        Q.push(next);
                        pre[next] = curr;
                    }
                }
            }
            if (pre[N] == -1) ans++;
            c[u][v]++;
        }
        
//        printf("%d\n", ans);
        
    }

    return 0;
}



