#include <bits/stdc++.h>
const int MAX = 1030;
using namespace std;

int N;
vector<int> graph[MAX];
int p[MAX];

struct edge{
	int u, v, w;
};

struct cmp{
	bool operator () (edge A, edge B){
		return A.w > B.w;
	}
};

int find(int node){
	if (p[node] == -1) return node;
	return p[node] = find(p[node]);
}

void merge(int A, int B){
	int roota = find(A);
	int rootb = find(B);
	if (roota == rootb) return;
	p[roota] = rootb;
	return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(p, -1, sizeof(p));
	scanf("%d", &N);
	priority_queue<edge, vector<edge>, cmp> PQ;
	for (int i=1;i<=N;i++){
		for (int j=i+1;j<=N;j++){
			int temp;
			scanf("%d", &temp);
			PQ.push({i, j, temp});
		}
	}
	
	int cnt = 0;
	while(cnt < N-1){
		auto curr = PQ.top(); PQ.pop();
		int u = curr.u, v = curr.v, w = curr.w;
		if (find(u) != find(v)){
			merge(u, v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			cnt++;
		}
	}
	for (int i=1;i<=N;i++){
		sort(graph[i].begin(), graph[i].end());
	}
	
	for (int i=1;i<=N;i++){
		printf("%d ", graph[i].size());
		for (int n: graph[i]){
			printf("%d ", n);
		}
		printf("\n");
	}
	
	return 0;
}


