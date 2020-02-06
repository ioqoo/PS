#include <bits/stdc++.h>
#define MAX_V 2020

using namespace std;

int C[MAX_V][MAX_V];
int F[MAX_V][MAX_V];
vector<int> graph[MAX_V];

// boj.kr/11377
// https://justicehui.github.io/ps/2019/03/17/BOJ11377/
// k명만 2개의 일을 할 수 있으면
// source ~ bridge ~ 직원 들을 연결하는 bridge 노드를 추가로 생성해준다
// source ~ bridge 용량은 K, bridge ~ 직원들 용량은 각각 1로 설정해주고
// 바로 EK 돌려주면 끝남
// 이분매칭도 결국 NF

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1;i<=n;i++){
		int S;
		scanf("%d", &S);
		for (int j=0;j<S;j++){
			int temp;
			scanf("%d", &temp);
			graph[i].push_back(n+temp);
			graph[n+temp].push_back(i);
			C[i][n+temp] = 1;
		}
	}
	for (int i=1;i<=n;i++){
		graph[0].push_back(i);
		graph[i].push_back(0);
		C[0][i] = 1;
	}
	for (int i=n+1;i<=n+m;i++){
		graph[i].push_back(n+m+1);
		graph[n+m+1].push_back(i);
		C[i][n+m+1] = 1;
	}
	graph[0].push_back(n+m+2); // K개만큼 흘려줄 bridge node
	graph[n+m+2].push_back(0);
	C[0][n+m+2] = k;
	for (int i=1;i<=n;i++){
		graph[n+m+2].push_back(i);
		graph[i].push_back(n+m+2);
		C[n+m+2][i] = 1;
	}

	int ans = 0;
	while(1){
		int prev[MAX_V];
		fill(prev, prev+MAX_V, -1);
		queue<int> Q;
		Q.push(0);
		while(!Q.empty() && prev[n+m+1] == -1){
			int curr = Q.front();
			Q.pop();
			for(auto next: graph[curr]){
				if (C[curr][next] - F[curr][next] > 0 && prev[next] == -1){
					Q.push(next);
					prev[next] = curr;
					if (next == n+m+1) break;
				}
			}
		}
		if (prev[n+m+1] == -1) break;

		for (int i=n+m+1;i!=0;i = prev[i]){
			F[prev[i]][i] += 1;
			F[i][prev[i]] -= 1;
		}
		ans += 1;
	}
	printf("%d\n", ans);

}