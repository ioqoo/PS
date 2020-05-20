#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 1005
#define INF 987654321

using namespace std;

int N, M;
int A, B, K, G;
int trav[MAX];
vector<pii> graph[MAX];
int adj[MAX][MAX];
pii forbid[MAX][MAX];
int u, v, w;
int dist[MAX];
bool visited[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &A, &B, &K, &G);
    for (int i=0;i<G;i++){
        scanf("%d", &trav[i]);
    }
    
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
        adj[u][v] = w;
        adj[v][u] = w;
    }
    
    int start = 0;
    for (int i=0;i<G-1;i++){
        forbid[trav[i]][trav[i+1]] = pii(start, start + adj[trav[i]][trav[i+1]]);
        forbid[trav[i+1]][trav[i]] = pii(start, start + adj[trav[i]][trav[i+1]]);
        start += adj[trav[i]][trav[i+1]];
    }
    
    fill(dist+1, dist+N+1, INF);
    dist[A] = K;
    PQ.push(pii(K, A));
    while(!PQ.empty()){
        auto p = PQ.top();
        PQ.pop();
        int curr = p.second, curr_dist = p.first;
        if (visited[curr]) continue;
        visited[curr] = true;
        for (auto pp: graph[curr]){
            int next = pp.first, weight = pp.second;
            auto F = forbid[curr][next];
            if (F.first <= curr_dist && curr_dist <= F.second){
                weight += F.second - curr_dist;
            }
            if (dist[next] > curr_dist + weight){
                dist[next] = curr_dist + weight;
                PQ.push(pii(dist[next], next));
            }
        }
    }
    
    printf("%d\n", dist[B] - K);
    

    return 0;
}

