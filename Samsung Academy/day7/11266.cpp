#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 10005

using namespace std;

int V, E;
vector<int> graph[MAX];
int order[MAX]; // order 로 방문 여부까지 한번에 체크 (0이면 미방문)
bool ans[MAX];
int cnt;

int dfs(int x, bool isRoot){
	// isRoot는 이 노드가 root 노드인지 -> root 노드일 때 자식의 개수가 2개 이상이라면 단절점
	
	order[x] = ++cnt; // 방문순서를 cnt를 늘려가며 order 배열에 입력해주고,
	int ret = order[x]; // 이번 노드의 방문 순서를 ret로 저장
	
	int child = 0;
	for (int next: graph[x]){
		if (!order[next]){ // 인접한 노드 중 방문한 노드는, 
			child++;
			int low = dfs(next, false); // 재귀적으로 다음 노드의 low 값을 받아와서 
			if (!isRoot && order[x] <= low){
			// root 노드가 아니고, 단절점이 되는 조건인 "order <= 다음 노드의 low" 를 만족하면 
				ans[x] = true; // 단절점 체크 
			}
			ret = min(ret, low); 
			// Line 25에서처럼 재귀적으로 low 값을 리턴해주어야 하기 때문에 
			// 인접한 노드들 중에서 min(curr 노드의 order, 인접한 노드들의 order(else 문), 인접한 노드들의 low)로
			// 이번 노드의 low를 결정 
		}
		else{
			ret = min(ret, order[next]);
		}
	}
	
	if (isRoot){
		ans[x] = (child >= 2);
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &V, &E);
	for (int i=0;i<E;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (int i=1;i<=V;i++){
		if (!order[i]) dfs(i, true);
	}
	
	int cnt = 0;
	for (int i=1;i<=V;i++){
		if (ans[i]) cnt++;
	}
	printf("%d\n", cnt);
	for (int i=1;i<=V;i++){
		if (ans[i]) printf("%d ", i);
	}
}
