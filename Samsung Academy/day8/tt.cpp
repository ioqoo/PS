#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 50005
#define PMAX 18
#define pii pair<int, int>
#define piii pair<int, pii>
#define ll long long
#define INF 9876543210LL
#define AAA printf("firstmax : %d / secondmax : %d\n", firstmax, secondmax);
#define BBB printf("MST_value : %d / curr_ST_value : %lld\n", MST_value, curr_ST_value);

using namespace std;

int V, E;
int p[MAX];
ll total_edge_value;
ll MST_value;
vector<pii> graph[MAX];

priority_queue<piii, vector<piii>, greater<piii>> PQ;
priority_queue<piii, vector<piii>, greater<piii>> notused_PQ;
vector<pii> MST[MAX];
int depth[MAX];
int lcaP[MAX][PMAX];
pii max_values[MAX][PMAX];

int find(int node){
	if (p[node] == -1) return node;
	
	return p[node] = find(p[node]);
}

void merge(int a, int b){
	int roota = find(a);
	int rootb = find(b);
	
	if (roota == rootb) return;
	p[roota] = rootb;
	return;
}

void maketree(int curr){
	for (auto p: MST[curr]){
		int next = p.first, weight = p.second;
		if (depth[next] == -1){
			depth[next] = depth[curr] + 1;
			lcaP[next][0] = curr;
			max_values[next][0] = pii(weight, -1);
			maketree(next);
		}
	}
	return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	memset(p, -1, sizeof(p));
	scanf("%d %d", &V, &E);
	
	
	for (int i=0;i<E;i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		total_edge_value += c;
		graph[u].push_back(pii(v, c));
		graph[v].push_back(pii(u, c));
		PQ.push(piii(c, pii(u, v)));
	}
	
	int edge_cnt = 0;
	while(!PQ.empty()){
		auto pp = PQ.top();
		PQ.pop();
		int weight = pp.first, u = pp.second.first, v = pp.second.second;
		if (find(u) != find(v)){
			merge(u, v);
			MST[u].push_back(pii(v, weight));
			MST[v].push_back(pii(u, weight));
			MST_value += weight;
			edge_cnt++;
		}
		else{
			notused_PQ.push(piii(weight, pii(u, v)));
		}
	}
	
	if (edge_cnt != V-1 || E <= V-1){
		printf("-1\n");
		return 0;
	}
	
	for (int i=1;i<=V;i++){
		for (int j=0;j<PMAX;j++){
			max_values[i][j] = pii(-1, -1);
		}
	}
	memset(lcaP, -1, sizeof(lcaP));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	maketree(1);
	
	for (int j=0;j<PMAX-1;j++){
		for (int i=1;i<=V;i++){
			if (lcaP[i][j] != -1){
				lcaP[i][j+1] = lcaP[lcaP[i][j]][j];
				pii half_below = max_values[i][j];
				int a = half_below.first, b = half_below.second;
				pii half_above = max_values[lcaP[i][j]][j];
				int c = half_above.first, d = half_above.second;
				vector<int> temp = {a, b, c, d};
				sort(temp.begin(), temp.end(), greater<int>());
				
				int firstmax = -1, secondmax = -1;
				
				for (int n: temp){
					firstmax = max(firstmax, n);
				}
				
				for (int n: temp){
					if (n==firstmax) continue;
					secondmax = max(secondmax, n);
				}
				max_values[i][j+1] = pii(firstmax, secondmax);
			}
		}
	}
	
//	for (int i=1;i<=V;i++){
//		for (int j=0;j<5;j++){
//			printf("%d %d // ", max_values[i][j].first, max_values[i][j].second);
//		}
//		printf("\n");
//	}
	
	ll ans = INF;
	while(!notused_PQ.empty()){
		auto pp = notused_PQ.top();
		notused_PQ.pop();
		int new_weight = pp.first, new_u = pp.second.first, new_v = pp.second.second;
		printf("new_weight : %d / new_u : %d / new_v : %d\n", new_weight, new_u, new_v);
		
		int firstmax = -1, secondmax = -1;
		int u = new_u, v = new_v;
		
		if (depth[u] < depth[v]) swap(u, v);
		
		
		int diff = depth[u] - depth[v];
		
		for (int i=0;diff;i++){
			if (diff%2) {
				int a = max_values[u][i].first, b = max_values[u][i].second;
				vector<int> temp = {firstmax, secondmax, a, b};
				sort(temp.begin(), temp.end(), greater<int>());
				firstmax = temp[0];
				for (int n:temp){
					if (n==firstmax) continue;
					secondmax = max(secondmax, n);
				}
				u = lcaP[u][i];
			}
			diff /= 2;
			
		}
		
		for (int j=PMAX-1;j>=0;j--){
			if (lcaP[u][j] != -1 && lcaP[u][j] != lcaP[v][j]){
				int a = max_values[u][j].first, b = max_values[u][j].second;
				int c = max_values[v][j].first, d = max_values[v][j].second;
				vector<int> temp = {a, b, c, d, firstmax, secondmax};
				sort(temp.begin(), temp.end(), greater<int>());
				firstmax = temp[0];
				for (int n: temp){
					if (n==firstmax) continue;
					secondmax = max(secondmax, n);
				}
				
				u = lcaP[u][j];
				v = lcaP[v][j];
			}
		}
		
		int a = max_values[u][0].first, b = max_values[u][0].second;
		int c = max_values[v][0].first, d = max_values[v][0].second;
		vector<int> temp = {a, b, c, d, firstmax, secondmax};
		sort(temp.begin(), temp.end(), greater<int>());
		firstmax = temp[0];
		for (int n: temp){
			if (n == firstmax) continue;
			secondmax = max(secondmax, n);
		}
		AAA
		
		if (firstmax != new_weight){
			ll curr_ST_value = MST_value - firstmax + new_weight;
			ans = min(ans, curr_ST_value);
			BBB
		}
		else if (secondmax != -1){
			ll curr_ST_value = MST_value - secondmax + new_weight;
			ans = min(ans, curr_ST_value);
			BBB
		}
		
		printf("\n");
	}
	
	if (ans == INF) {
		printf("-1\n");
	}
	else{
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
