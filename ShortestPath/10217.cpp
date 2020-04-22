#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>

#define pii pair<int, int>
#define piii pair<int, pii>
#define MAX 105
#define INF 987654321

using namespace std;

int T, N, M, K;
vector<piii> graph[MAX];
int dist[MAX][10005];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T>0){
        T--;
        
        scanf("%d %d %d", &N, &M, &K);
        for (int i=1;i<=N;i++){
            graph[i].clear();
            for (int j=1;j<=M;j++){
                dist[i][j] = INF;
            }
        }
        
        int u, v, c, w;
        for (int i=0;i<K;i++){
            scanf("%d %d %d %d", &u, &v, &c, &w);
            graph[u].push_back(piii(v, pii(c, w))); // next, cost, weight
        }
        
        dist[1][0] = 0;
        priority_queue<piii, vector<piii>, greater<piii>> PQ;
        PQ.push(piii(0, pii(1, 0))); // curr_dist, curr, cost
        while(!PQ.empty()){
            auto p = PQ.top();
            PQ.pop();
            int curr = p.second.first, curr_dist = p.first, curr_cost = p.second.second;
            if (dist[curr][curr_cost] < curr_dist) continue;
            for (auto pp: graph[curr]){
                int next = pp.first, next_cost = pp.second.first, next_weight = pp.second.second;
                if (curr_cost + next_cost <= M){
                    if (dist[next][curr_cost + next_cost] > dist[curr][curr_cost] + next_weight){
                        dist[next][curr_cost + next_cost] = dist[curr][curr_cost] + next_weight;
                        PQ.push(piii(dist[next][curr_cost + next_cost], pii(next, curr_cost + next_cost)));
                    }
                }
            }
        }
        int ans = INF;
        for (int i=1;i<=M;i++){
            ans = min(ans, dist[N][i]);
        }
        ans == INF ? printf("Poor KCM\n") : printf("%d\n", ans);
    }
    return 0;
}

