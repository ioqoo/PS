#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 10005

using namespace std;

int N;
vector<int> graph[MAX];
queue<int> Q;
int indegree[MAX];
int t[MAX];
int total[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	scanf("%d", &N);
	for (int u=1;u<=N;u++){
		scanf("%d", &t[u]);
		int E;
		scanf("%d", &E);
		for (int i=0;i<E;i++){
			int v;
			scanf("%d", &v);
			graph[v].push_back(u);
			indegree[u]++;
		}
	}
	
	for (int i=1;i<=N;i++){
		if (indegree[i] == 0) {
			Q.push(i);
			total[i] = t[i];
		}
	}
	
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for (int i=0;i<graph[curr].size();i++){
			int next = graph[curr][i];
//			printf("%d %d\n", curr, next);
			indegree[next]--;
			total[next] = max(total[next], total[curr] + t[next]);
			if (indegree[next] == 0) Q.push(next);
		}
	}
	int ans = 0;
	for (int i=1;i<=N;i++){
		ans = max(ans, total[i]);
	}
	printf("%d\n", ans);

    return 0;

}
