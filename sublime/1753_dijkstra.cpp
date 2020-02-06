#include <bits/stdc++.h>
#define INF 123456789
#define pii pair<int, int>

using namespace std;

int V, E, K;
vector<pii> adj[20001];
int dist[20001];
bool visited[20001];
priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main(){
	scanf("%d %d %d", &V, &E, &K);
	K--;

	fill(dist, dist+20001, INF);

	for (int i=0;i<E;i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(pii(v-1, w));
	}
	dist[K] = 0;
	PQ.push(pii(0, K));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;

		visited[curr] = true;
		for (int i=0;i<adj[curr].size();i++){
			int next = adj[curr][i].first;
			int d = adj[curr][i].second;
			if (dist[next] > dist[curr]+d){
				dist[next] = dist[curr] + d;
				PQ.push(pii(dist[next], next));
			}
		}
	}

	for (int i=0;i<V;i++){
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

}