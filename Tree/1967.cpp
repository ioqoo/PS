#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 10005

using namespace std;

int N;
vector<pii> graph[MAX];
int dist[MAX];
bool visited[MAX];

void dfs(int curr){
    visited[curr] = true;
    for (auto p: graph[curr]){
        int next = p.first, weight = p.second;
        if (visited[next]) continue;
        dist[next] = dist[curr] + weight;
        dfs(next);
    }
    return;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int u, v, w;
    for (int i=0;i<N-1;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
    }
    
    dfs(1);
    
    int S, max_dist = -1;
    for (int i=1;i<=N;i++){
        if (max_dist < dist[i]){
            max_dist = dist[i];
            S = i;
        }
    }
    
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    
    dfs(S);
    
    int ans = *max_element(dist+1, dist+N+1);
    printf("%d\n", ans);

    return 0;
}

