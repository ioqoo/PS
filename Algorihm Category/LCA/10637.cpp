#include <bits/stdc++.h>
#define ll long long
const int NMAX = 100005;
const int MMAX = 200005;
const int PMAX = 20;
using namespace std;

struct edge{
	int u, v, w, num;
};

struct cmp{
	bool operator () (edge A, edge B){
		return A.w > B.w;
	}
};

struct edge_tree{
	int to, w, num;
};

int N, M;
ll MST_val;
int p[NMAX];
int p_LCA[NMAX][PMAX], depth[NMAX], jump[NMAX];
bool MST_edge[MMAX];
ll ans[MMAX];
edge_tree node_to_edge[NMAX]; // node_to_edge[a] = a에서 a의 부모 노드로 가는 edge num 
vector<edge> edge_list;
vector<edge_tree> MST[NMAX];
priority_queue<edge, vector<edge>, cmp> PQ_MST;
priority_queue<edge, vector<edge>, cmp> PQ_NOT_MST;


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

void make_tree(int curr){
	for (auto P: MST[curr]){
		if (depth[P.to] != -1) continue;
		depth[P.to] = depth[curr] + 1;
		p_LCA[P.to][0] = curr;
		jump[P.to] = curr;
		node_to_edge[P.to] = {curr, P.w, P.num};
		make_tree(P.to);
	}
}

void LCA_preprocess(){
	for (int j=0;j<PMAX;j++){
		for (int i=1;i<=N;i++){
			if (p_LCA[i][j] != -1){
				p_LCA[i][j+1] = p_LCA[p_LCA[i][j]][j];
			}
		}
	}
}

int get_LCA(int u, int v){
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for (int i=0;diff;i++){
		if (diff%2) u = p_LCA[u][i];
		diff /= 2;
	}
	if (u != v){
		for (int j=PMAX-1;j>=0;j--){
			if (p_LCA[u][j] != -1 && p_LCA[u][j] != p_LCA[v][j]){
				u = p_LCA[u][j];
				v = p_LCA[v][j];
			}
		}
		u = p_LCA[u][0];
	}
	return u;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &M);
	
	memset(p, -1, sizeof(p));
	memset(p_LCA, -1, sizeof(p_LCA));
	memset(depth, -1, sizeof(depth));
	memset(ans, -1, sizeof(ans));
	
	for (int i=0;i<M;i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge_list.push_back({u, v, w, i});
		PQ_MST.push({u, v, w, i});
	}
	
	int merge_cnt = 0;
	while(!PQ_MST.empty()){
		auto P = PQ_MST.top(); PQ_MST.pop();
		if (find(P.u) != find(P.v)){
			merge(P.u, P.v);
			merge_cnt++;
			MST_val += (ll)P.w;
			MST[P.u].push_back({P.v, P.w, P.num});
			MST[P.v].push_back({P.u, P.w, P.num});
			MST_edge[P.num] = true;
		}
		else{
			PQ_NOT_MST.push(P);
		}
	}
	
	if (merge_cnt != N-1){
		for (int i=0;i<M;i++){
			printf("-1\n");
		}
		return 0;
	}
	
	depth[1] = 0;
	jump[1] = -1;
	make_tree(1);
	LCA_preprocess();
	
	int replace_cnt = 0;
	
	while(!PQ_NOT_MST.empty()){
		auto P = PQ_NOT_MST.top(); PQ_NOT_MST.pop();
		ans[P.num] = MST_val;
		int LCA = get_LCA(P.u, P.v);
		int u = P.u, v = P.v;
		if (u != LCA){
			while(1){
				auto curr_edge = node_to_edge[u];
				if (ans[curr_edge.num] == -1){
					ans[curr_edge.num] = MST_val - (ll)curr_edge.w + (ll)P.w;
					replace_cnt++;
				}
				int origin_u = u;
				u = jump[u];
				if (depth[origin_u] > depth[LCA]) jump[origin_u] = LCA;
				if (depth[u] <= depth[LCA]) break;
			}
		}
		if (v != LCA){
			while(1){
				auto curr_edge = node_to_edge[v];
				if (ans[curr_edge.num] == -1){
					ans[curr_edge.num] = MST_val - (ll)curr_edge.w + (ll)P.w;
					replace_cnt++;
				}
				int origin_v = v;
				v = jump[v];
				if (depth[origin_v] > depth[LCA]) jump[origin_v] = LCA;
				if (depth[v] <= depth[LCA]) break;
			}
		}
		if (replace_cnt == N-1) break;
	}
	
	for (int i=0;i<M;i++){
		if (!MST_edge[i]) printf("%lld\n", MST_val);
		else printf("%lld\n", ans[i]);
	}
	
	
	
	return 0;
}


