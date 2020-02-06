#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 123456789
using namespace std;

int N, indegree[501];
int time_arr[501];
int result[501];
queue<int> Q;
vector<int> graph[501];
vector<int> ans;

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &time_arr[i]);
		while(1){
			int n;
			scanf("%d", &n);
			if (n==-1) break;
			indegree[i]++;
			graph[n].push_back(i);
		}
	}

	for (int i=1;i<=N;i++){
		if (indegree[i]==0) {
			Q.push(i);
			result[i] = time_arr[i];
		}
	}

	for (int i=1;i<=N;i++){
		int curr = Q.front();
		Q.pop();
		ans.push_back(curr);
		for (auto next: graph[curr]){
			if (--indegree[next]==0) Q.push(next);
		}
	}

	for (auto u: ans){
		for (auto v: graph[u]){
			result[v] = max(result[v], result[u]+time_arr[v]);
		}
	}

	for (int i=1;i<=N;i++){
		printf("%d\n", result[i]);
	}
}