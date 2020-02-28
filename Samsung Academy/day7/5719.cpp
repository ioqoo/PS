#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

#define pii pair<int, int>
#define MAX 503
#define INF 987654321

using namespace std;

int N, M, S, D;
int dist[MAX];
bool available[MAX][MAX]; // available[i][j] = i -> j로 가는 간선은 최단 경로에 포함됨. 
bool visited[MAX];
vector<pii> graph[MAX];
vector<pii> rev_graph[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    while(1){
        
        scanf("%d %d", &N, &M);
        if (N==0 && M==0) break;
        
        for (int i=0;i<N;i++){
            dist[i] = INF;
        }
        memset(visited, 0, sizeof(visited));
        memset(available, 0, sizeof(available));
        
        for (int i=0;i<N;i++){
            graph[i].clear();
            rev_graph[i].clear();
        }
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        
        
        scanf("%d %d", &S, &D);
        
        
        for (int i=0;i<M;i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(pii(v, w));
            rev_graph[v].push_back(pii(u, w));
        }
        
        dist[S] = 0;
        PQ.push(pii(0, S));
        
        while(!PQ.empty()){
            auto p = PQ.top();
            PQ.pop();
            int curr = p.second, curr_dist = p.first;
            visited[curr] = true;
            for (auto pp: graph[curr]){
                int next = pp.first, weight = pp.second;
                if (!visited[next] && dist[next] > curr_dist + weight){
                    dist[next] = curr_dist + weight;
                    PQ.push(pii(dist[next], next));
                }
            }
        }
        if (dist[D] == INF) {
            printf("-1\n");
            continue;
        }
        
        queue<pii> Q;
        Q.push(pii(D, dist[D]));
        while(!Q.empty()){
            auto pp = Q.front();
            int curr = pp.first, curr_remain = pp.second;
            Q.pop();
            for (auto ppp: rev_graph[curr]){
                int next = ppp.first, weight = ppp.second;
                if (curr_remain - weight == dist[next]){
                    available[next][curr] = true;
                    Q.push(pii(next, dist[next]));
                }
            }
        }
        for (int i=0;i<N;i++){
            dist[i] = INF;
        }
        memset(visited, 0, sizeof(visited));
        
        dist[S] = 0;
        PQ.push(pii(0, S));
        while(!PQ.empty()){
            auto p = PQ.top();
            PQ.pop();
            int curr = p.second, curr_dist = p.first;
            visited[curr] = true;
            for (auto pp: graph[curr]){
                int next = pp.first, weight = pp.second;
                if (!visited[next] && !available[curr][next] && dist[next] > curr_dist + weight){
                    dist[next] = curr_dist + weight;
                    PQ.push(pii(dist[next], next));
                }
            }
        }
        if (dist[D] == INF) printf("-1\n");
        else printf("%d\n", dist[D]);
        
    } 
    
    return 0;
} 
