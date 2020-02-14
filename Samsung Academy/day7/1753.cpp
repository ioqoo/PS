#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define pii pair<int, int>
#define MAX 20005
#define INF 987654321

using namespace std;

int V, E, K;
vector<pii> graph[MAX];
int dist[MAX];
bool visited[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d %d", &V, &E, &K);
	for (int i=0;i<E;i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(pii(v, w));
	}
	
	for (int i=1;i<=V;i++){
		dist[i] = INF;
	}
	
	dist[K] = 0;
	PQ.push(pii(0, K));
	
	while(!PQ.empty()){
		auto p = PQ.top();
		PQ.pop();
		int curr_dist = p.first, curr = p.second;
		if (visited[curr]) continue;
		
		visited[curr] = true;
		
		for (auto p: graph[curr]){
			int next_w = p.second, next = p.first;
			if (dist[next] > curr_dist + next_w){
				dist[next] = curr_dist + next_w;
				PQ.push(pii(dist[next], next));
			}
		}
	}
	
	for (int i=1;i<=V;i++){
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	
	return 0;
}
