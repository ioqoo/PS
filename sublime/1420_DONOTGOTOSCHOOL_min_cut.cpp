#include <bits/stdc++.h>
#define ll long long
#define MAX 987654321
using namespace std;

struct Edge{
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
	int spare(){
		return c - f;
	}
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

int n, m;
int grid[105][105];
int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};
vector<Edge*> graph[20005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int K, H;
	int node_num = 0;
	for (int i=0;i<n;i++){
		string row;
		cin >> row;
		for (int j=0;j<m;j++){
			char curr = row[j];
			if (curr == '#'){
				grid[i][j] = -1;
			}
			else {
				grid[i][j] = node_num;
				if (curr == 'K'){
					K = node_num*2 + 1;
				}
				else if (curr == 'H'){
					H = node_num*2;
				}
				node_num++;
			}
		}
	}
//	for (int i=0;i<n;i++){
//		for (int j=0;j<m;j++){
//			cout << grid[i][j] << " ";
//		}
//		cout << endl;
//	}

	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			int u = grid[i][j];
			if (u == -1) continue;

			Edge *e1 = new Edge(u*2+1, 1), *e2 = new Edge(u*2, 0); // n*2 : in, n*2+1 : out
			e1->dual = e2;
			e2->dual = e1;
			graph[u*2].push_back(e1);
			graph[u*2+1].push_back(e2);
			for (int k=0;k<4;k++){
				int ni = i + di[k], nj = j + dj[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m){
					if (grid[ni][nj]!=-1){
						int v = grid[ni][nj];
						Edge *e3 = new Edge(v*2, MAX), *e4 = new Edge(u*2+1, 0);
						e3->dual = e4;
						e4->dual = e3;
						graph[u*2+1].push_back(e3);
						graph[v*2].push_back(e4);
					}
				}
			}
		}
	}

	int ans = 0;
	while(1){
		int prev[20005];
		fill(prev, prev+20005, -1);
		Edge *path[20005] = {0,};
		queue<int> Q;
		Q.push(K);
		while(!Q.empty() && prev[H] == -1){
			int curr = Q.front();
			Q.pop();
			for (Edge *e: graph[curr]){
				int next = e->to;
				if (e->spare() > 0 && prev[next] == -1){
					Q.push(next);
					prev[next] = curr;
					path[next] = e;
					if (next == H) break;
				}
			}
		}
		if (prev[H] == -1) break;
		if (prev[H] == K) {
			printf("-1");
			return 0;
		}

		for (int i=H;i!=K;i=prev[i]){
			path[i]->addFlow(1);
		}
		ans += 1;
	}
	cout << ans << endl;


}
