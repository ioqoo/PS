#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define pii pair<int, int>
#define MAX 1003
#define INF 987654321

using namespace std;

int N, M, K;
vector<pii> graph[MAX];
int dist[MAX];
int cnt[MAX];
int ans[MAX];
bool visited[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ; // (dist, node)



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d %d", &N, &M, &K);
	for (int i=0;i<M;i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		graph[u].push_back(pii(v, c));
	}
	
	for (int i=1;i<=N;i++){
		ans[i] = -1;
	}
	
	cnt[1] = 0;
//	dist[1] = 0;
	PQ.push(pii(0, 1));
	while(!PQ.empty()){
		auto p = PQ.top();
		PQ.pop();
		int curr_dist = p.first, curr = p.second;
		if (cnt[curr] == K) continue;
		cnt[curr]++;
		if (cnt[curr] == K) {
			ans[curr] = curr_dist;
//			continue;
		}
		for (auto pp: graph[curr]){
			int next = pp.first, weight = pp.second;
			int cand = curr_dist + weight;
//			if (cand < dist[next]){
//				dist[next] = cand;
//			}
			PQ.push(pii(cand, next));
		}
	}
	
	for (int i=1;i<=N;i++){
		printf("%d\n", ans[i]);
	}
	
	
	return 0;
} 
