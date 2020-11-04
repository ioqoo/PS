#include <bits/stdc++.h>
const int MAX = 100005;
using namespace std;

struct edge{
	int to, w;
};

struct edge_pair{
	int u, v;
};

edge_pair edge_ind[MAX];

int N, M, leaf_size;
vector<edge> graph[MAX];
int sz[MAX], par[MAX];

int dfs(int curr, int parent){
	par[curr] = parent;
	sz[curr] = 1;
	for (auto p: graph[curr]){
		int next = p.to;
		if (next != parent) sz[curr] += dfs(next, curr);
	}
	return sz[curr];
}

int piv;
int chain_num[MAX], chain_depth[MAX], chain_index[MAX];

void HLD(int curr, int parent, int curr_chain_num, int curr_depth){
	chain_depth[curr] = curr_depth;
	chain_num[curr] = curr_chain_num;
	chain_index[curr] = piv++;
	
	int heavy = -1;
	for (auto p: graph[curr]){
		int next = p.to;
		if (next != parent && (heavy == -1 || sz[next] > sz[heavy])){
			heavy = next;
		}
	}
	if (heavy != -1){
		HLD(heavy, curr, curr_chain_num, curr_depth);
	}
	for (auto p: graph[curr]){
		int next = p.to;
		if (next != parent && next != heavy){
			HLD(next, curr, next, curr_depth+1);
		}
	}
}

int tree[MAX*4];

void seg_init(){
	for (int i=leaf_size-1;i>=1;i--){
		tree[i] = max(tree[i*2], tree[i*2+1]);
	}
}

void seg_update(int pos, int val){
	pos += leaf_size;
	tree[pos] = val;
	while(pos > 1){
		pos /= 2;
		tree[pos] = max(tree[pos*2], tree[pos*2+1]);
	}
}

int seg_getmax(int node, int l, int r, int s, int e){
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return tree[node];
	int mid = (l+r) / 2;
	return max(seg_getmax(node*2, l, mid, s, e), seg_getmax(node*2+1, mid+1, r, s, e));
}

void HLD_init(int curr, int parent){
	for (auto p: graph[curr]){
		int next = p.to, weight = p.w;
		if (next == parent) continue;
		tree[chain_index[next] + leaf_size] = weight;
		HLD_init(next, curr);
	}
}

void query_update(int n, int val){
	auto E = edge_ind[n];
	int u = E.u, v = E.v;
	if (u == par[v]) swap(u, v);
	seg_update(chain_index[u], val);
}

int query_getmax(int u, int v){
	int ret = 0;
	while(chain_num[u] != chain_num[v]){
		if (chain_depth[u] < chain_depth[v]) swap(u, v);
		ret = max(ret, seg_getmax(1, 0, leaf_size-1, chain_index[chain_num[u]], chain_index[u]));
		u = par[chain_num[u]];
	}
	if (chain_index[u] > chain_index[v]) swap(u, v);
	ret = max(ret, seg_getmax(1, 0, leaf_size-1, chain_index[u] + 1, chain_index[v]));
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=1;i<=N-1;i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
		edge_ind[i] = {u, v};
	}
	dfs(1, 0);
	HLD(1, 0, 1, 0);
	HLD_init(1, 0);
	seg_init();
	
	scanf("%d", &M);
	for (int i=0;i<M;i++){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (op == 1){
			query_update(a, b);
		}
		else{
			printf("%d\n", query_getmax(a, b));
		}
	}
	
	
	return 0;
}


