#include <bits/stdc++.h>
#define MAX_V 2010
using namespace std;

// https://www.acmicpc.net/problem/3295
// 정점을 두 개로 분리 : 나가는 점, 들어오는 점
// 문제를 보면 degree와 indegree가 각각 2 이상일 수가 없다
// -> 간선의 개수가 시스템의 가치, 즉 이분매칭

int n, m, A[MAX_V], B[MAX_V];
vector<int> graph[MAX_V];
bool visited[MAX_V];

bool dfs(int a){
	visited[a] = true;
	for (int b: graph[a]){
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		fill(visited, visited+MAX_V, false);
		fill(A, A+MAX_V, -1);
		fill(B, B+MAX_V, -1);
		for (int i=0;i<MAX_V;i++){
			graph[i].clear();
		}
		for (int x=0;x<m;x++){
			int u, v;
			scanf("%d %d", &u, &v);
			graph[2*u].push_back(2*v+1);
		}
		int ans = 0;
		for (int i=0;i<=2*n-1;i++){
			if (A[i] == -1){
				fill(visited, visited+MAX_V, false);
				if (dfs(i)) ans++;
			}
		}
		printf("%d\n", ans);
	}
}