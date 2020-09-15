#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

int ans[1503][1503];
int graph[4003][2];
int node_to_col[4003];
// graph[i][j]
// i번째 node가 옆으로(j=0), 아래로(j=1) 연결된 node 
vector<int> col_pos[1503];
map<int, int> mp[4003]; // <column, erase cnt>

void solve(int node_num){
	int side_node_num = graph[node_num][0];
	int side_down_node_num = graph[side_node_num][1];
	int down_node_num = graph[node_num][1];
//	printf("curr_num : %d\n", node_num);
	
//	map<int, int> curr_node_map = mp[node_num];
	
	int curr_num = side_down_node_num;
	int removed = 0;
	while(curr_num != -1){
		if (mp[curr_num].empty()) solve(curr_num);
//		printf("size : %d\n", mp[curr_num].size());
		for (auto p: mp[curr_num]){
			int to_col = p.first;
			int erase_cnt = p.second;
//			printf("to_col : %d\n", to_col);
			if (!mp[node_num].count(to_col)) mp[node_num][to_col] = erase_cnt + removed;
			else mp[node_num][to_col] = min(mp[node_num][to_col], erase_cnt + removed);
		}
		removed++;
		curr_num = graph[curr_num][1];
	}
	
	if (!mp[node_num].count(node_to_col[side_node_num])) mp[node_num][node_to_col[side_node_num]] = removed;
	else mp[node_num][node_to_col[side_node_num]] = min(mp[node_num][node_to_col[side_node_num]], removed);
	
	
}


int main(int argc, char** argv){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++){
		printf("Case #%d\n", t);
		
		int N, K, M;
		scanf("%d %d %d", &N, &K, &M);
		memset(graph, -1, sizeof(graph));
		memset(node_to_col, 0, sizeof(node_to_col));
		for (int i=1;i<=N;i++){
			for (int j=1;j<=N;j++){
				ans[i][j] = -1;
			}
		}
		for (int i=0;i<2*K;i++){
			mp[i].clear();
		}
		
		vector<int> pre_up(N+1, -1);
		vector<int> init(N+1, -1);
		
		for (int i=0;i<K;i++){
			int a, b;
			scanf("%d %d", &a, &b);
			int num_a = i*2, num_b = i*2+1;
			node_to_col[num_a] = a; node_to_col[num_b] = b;
			graph[num_a][0] = num_b;
			graph[num_b][0] = num_a;
			if (pre_up[a] != -1){
				graph[pre_up[a]][1] = num_a;
			}
			else{
				init[a] = num_a;
			}
			if (pre_up[b] != -1){
				graph[pre_up[b]][1] = num_b;
			}
			else{
				init[b] = num_b;
			}
			pre_up[a] = num_a;
			pre_up[b] = num_b;
		}
		
//		for (int i=1;i<=N;i++){
//			solve(init[i]);
//		}
		
		for (int i=1;i<=N;i++){
			int node_num = init[i];
			int removed = 0;
//			printf("curr_start : %d\n", i);
			while(node_num != -1){
//				printf("curr node : %d\n", node_num);
				if (mp[node_num].empty()) solve(node_num);
				for (auto p: mp[node_num]){
					int to_col = p.first;
					int erase_cnt = p.second;
					if (ans[i][to_col] == -1) ans[i][to_col] = erase_cnt + removed;
					else ans[i][to_col] = min(ans[i][to_col], erase_cnt + removed);
				}
				removed++;
				node_num = graph[node_num][1];
			}
			if (ans[i][i] == -1) ans[i][i] = removed;
			else ans[i][i] = min(ans[i][i], removed);
		}
		
		int sum = 0;
		for (int i=0;i<M;i++){
			int a, b;
			scanf("%d %d", &a, &b);
			sum += ans[a][b];
		}
		printf("%d\n", sum);
		
		
		
		
	}
	
	return 0;
}

