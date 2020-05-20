#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

#define pii pair<int, int>
#define INF 1987654321
#define MAX 10005

using namespace std;

int N, M, S, E;
vector<pii> graph[MAX];
vector<pii> graph_rev[MAX];
int dist[MAX];
bool visited[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	int u, v, w;
	for (int i=0;i<M;i++){
	    scanf("%d %d %d", &u, &v, &w);
	    graph[u].push_back(pii(v, -w));
	    graph_rev[v].push_back(pii(u, -w));
    }
    scanf("%d %d", &S, &E);
    
    fill(dist, dist+MAX, INF);
    dist[S] = 0;
    PQ.push(pii(0, S));
    while(!PQ.empty()){
        auto p = PQ.top();
        PQ.pop();
        int curr = p.second, curr_dist = p.first;
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
    printf("%d\n", -dist[E]);
    
    for (int i=1;i<=N;i++){
        printf("%d ", -dist[i]);
    }
    printf("\n");
    
    int edge_cnt = 0;
    queue<int> Q;
    memset(visited, 0, sizeof(visited));
    Q.push(E);
    visited[E] = true;
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for (auto pp: graph_rev[curr]){
            int next = pp.first, weight = pp.second;
            if (dist[curr] - weight == dist[next]){
                edge_cnt++;
                if (!visited[next]){
                    Q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    printf("%d\n", edge_cnt);

	return 0;
}

