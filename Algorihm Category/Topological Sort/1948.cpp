#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 10005
#define pii pair<int, int>

using namespace std;

int N, M, S, E;
vector<pii> graph[MAX];
vector<pii> graph_rev[MAX];
int indegree[MAX];
int dist[MAX];
bool visited[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    int u, v, w;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        indegree[v]++;
        graph_rev[v].push_back(pii(u, w));
    }
    scanf("%d %d", &S, &E);
    
    queue<int> Q;
    for (int i=1;i<=N;i++){
        if (indegree[i] == 0) Q.push(i);
    }
    
    for (int i=0;i<N;i++){
        int curr = Q.front();
        Q.pop();
        for (auto p: graph[curr]){
            int next = p.first, weight = p.second;
            indegree[next]--;
            dist[next] = max(dist[next], dist[curr] + weight);
            if (indegree[next] == 0){
                Q.push(next);
            }
        }
    }    
    printf("%d\n", dist[E]);
    
    int edge_cnt = 0;
    queue<int> trav;
    trav.push(E);
    visited[E] = true;
    
    while(!trav.empty()){
        int curr = trav.front();
        trav.pop();
        for (auto p: graph_rev[curr]){
            int next = p.first, weight = p.second;
            if (dist[curr] - weight == dist[next]){
                edge_cnt++;
                if (!visited[next]){
                    trav.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    printf("%d\n", edge_cnt);
    

    return 0;

}
