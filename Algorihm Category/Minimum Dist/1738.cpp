#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>

#define pii pair<int, int>
#define MAX 105
#define INF 200000000

using namespace std;

int N, M;
int dist[MAX];
int previ[MAX];
bool visited[MAX];
vector<pii> graph[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	int u, v, w;
	for (int i=0;i<M;i++){
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(pii(v, -w));
	}
	
	for (int i=1;i<MAX;i++){
		dist[i] = INF;
	}
	dist[1] = 0;
	int cycle_elem;
	bool neg_cycle = false;
	for (int x=1;x<=N-1;x++){
		for (int curr=1;curr<=N;curr++){
			if (dist[curr] == INF) continue;
			for (auto p: graph[curr]){
				int next = p.first;
				int weight = p.second;
				if (dist[next] > dist[curr] + weight){
					dist[next] = dist[curr] + weight;
					previ[next] = curr;
					if (x == N-1 && curr != 1){
						neg_cycle = true;
						cycle_elem = curr;
					}
				}
			}
		}
	}
	
	if (dist[N] == INF){
		printf("-1\n");
		return 0;
	}
	if (neg_cycle){
		queue<int> Q;
		Q.push(cycle_elem);
		visited[cycle_elem] = true;
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for (auto p: graph[curr]){
				int next = p.first;
				if (!visited[next]){
					Q.push(next);
					visited[next] = true;
				}
			}
		}
		if (visited[N]){
			printf("-1\n");
			return 0;
		}
	}
	stack<int> ans;
	for (int curr=N;curr!=1;curr=previ[curr]){
		ans.push(curr);
	}
	ans.push(1);
	while(!ans.empty()){
		printf("%d ", ans.top());
		ans.pop();
	}
	
	
	
	return 0;
}
