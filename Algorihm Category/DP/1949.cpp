#include <bits/stdc++.h>
const int MAX = 10005;
using namespace std;

int N;
int pop[MAX]; 
vector<int> graph[MAX];
int dp[MAX][2];
bool visited[MAX];
// dp[i][j] : i��° ���ø� ��������� j(bool) ���� ��
// �� ��� ���� ����Ʈ������ ���� �� �ִ� ��� ���� �ֹ� ���� �� �� 

int solve(int curr, bool is_good){
	int &ret = dp[curr][is_good];
	if (ret != -1) return ret;
	ret = 0;
	visited[curr] = true;
	if (is_good){
		for (int next: graph[curr]){
			if (visited[next]) continue;
			ret += solve(next, false);
		}
		return ret;
	}
	else{
		for (int next: graph[curr]){
			if (visited[next]) continue;
			ret += max(solve(next, false), solve(next, true) + pop[next]);
		}
	}
	
	visited[curr] = false;
	return ret;	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &pop[i]);
	}
	
	for (int i=0;i<N-1;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	memset(dp, -1, sizeof(dp));
	
	printf("%d\n", max(solve(1, 0), solve(1, 1) + pop[1]));
 
	
	return 0;
}


