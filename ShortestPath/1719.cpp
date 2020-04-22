#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 205
#define INF 987654321

using namespace std;

int N, M;
vector<pii> graph[MAX];
int dist[MAX];
bool visited[MAX];
//int previ[MAX];
int u, v, w;
int ans[MAX][MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
    }
    
    for (int S=1;S<=N;S++){
        fill(dist+1, dist+N+1, INF);
        memset(visited, 0, sizeof(visited));
//        memset(previ, 0, sizeof(previ));
        
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        dist[S] = 0;
        PQ.push(pii(0, S));
        while(!PQ.empty()){
            auto p = PQ.top();
            int curr = p.second, curr_dist = p.first;
            PQ.pop();
            if (visited[curr]) continue;
            visited[curr] = true;
            for (auto pp: graph[curr]){
                int next = pp.first, weight = pp.second;
                if (dist[next] > curr_dist + weight){
                    dist[next] = curr_dist + weight;
                    PQ.push(pii(dist[next], next));
                }
            }
        }
        
//        for (int i=1;i<=N;i++){
//            printf("%12d ", dist[i]);
//        }
//        printf("\n");
        
        for (int D=1;D<=N;D++){
            if (D == S) continue;
            memset(visited, 0, sizeof(visited));
            queue<int> Q;
            Q.push(D);
            bool succ = false;
            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                for (auto p: graph[curr]){
                    int next = p.first, weight = p.second;
                    if (dist[curr] - weight == dist[next]){
//                        previ[curr] = next;
                        if (!visited[next]){
                            visited[next] = true;
                            Q.push(next);
                        }
                        if (next == S){
                            ans[S][D] = curr;
                            succ = true;
                            break;
                        }
                    }
                }
                if (succ) break;
            }
        }
    }
    
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (ans[i][j] == 0) printf("- ");
            else printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    
    
	return 0;
}

