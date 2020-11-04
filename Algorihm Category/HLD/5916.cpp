#include <bits/stdc++.h>
#define ll long long
const int NMAX = 100005;
using namespace std;

int N, M;
vector<int> graph[NMAX];

int sz[NMAX], par[NMAX];

int piv;
int chain_depth[NMAX], chain_num[NMAX], chain_index[NMAX];
// chain_depth : �� ��尡 ���� ü���� depth 
// chain_num : �� ��尡 �� �� ü�ο� ���� �ִ� ü�� #, �� #�� ü���� ���� ������� ��� ��ȣ
// chain_index : HLD�� ����� ������ �Ʒ��� �����ϴ� ������ ������ ���ο� ����� ��ȣ (0-index)
// ü���� ������ ������ ü�� depth�� ���߸鼭 ���� �ø��� LCA�� ���� �� ����
// �� �������� ������ (���� ��� ~ ü���� ����� ���)�� chain_index���� �������� ���� ����
// �� index�� �̿��ؼ� ���� query�� ó���� �� �ִ�.  
int leaf_size = NMAX * 2;
ll tree[NMAX*4], lazy[NMAX*4];


int dfs_sz_and_par(int curr, int parent){
	par[curr] = parent;
	sz[curr] = 1;
	for (int next: graph[curr]){
		if (next != parent) sz[curr] += dfs_sz_and_par(next, curr);
	}
	return sz[curr];
}

void HLD(int curr, int parent, int curr_chain_num, int curr_depth){
	chain_depth[curr] = curr_depth;
	chain_num[curr] = curr_chain_num;
	chain_index[curr] = piv++;
	
	int heavy = -1;
	for (int next: graph[curr]){
		if (next != parent && (heavy == -1 || sz[next] > sz[heavy])) {
			heavy = next;
		}
	}
	if (heavy != -1){ // heavy edge ; same chain
		HLD(heavy, curr, curr_chain_num, curr_depth);
	}
	for (int next: graph[curr]){ // light edge ; new chain
		if (next != parent && next != heavy){
			HLD(next, curr, next, curr_depth+1);
		}
	}
}

void propagate(int node, int l, int r){
	if (lazy[node]){
		if (l != r){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		tree[node] += lazy[node] * (r-l+1);
		lazy[node] = 0;
	}
}

void seg_update(int node, int l, int r, int s, int e, ll diff){
	propagate(node, l, r);
	if (r < s || e < l) return;
	if (s <= l && r <= e) {
		lazy[node] += diff;
		propagate(node, l, r);
		return;
	}
	int mid = (l+r) / 2;
	seg_update(node*2, l, mid, s, e, diff);
	seg_update(node*2+1, mid+1, r, s, e, diff);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll seg_getsum(int node, int l, int r, int s, int e){
	propagate(node, l, r);
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return tree[node];
	int mid = (l+r) / 2;
	return seg_getsum(node*2, l, mid, s, e) + seg_getsum(node*2+1, mid+1, r, s, e);
}

void query_update(int u, int v, ll diff){
	while(chain_num[u] != chain_num[v]){
		if (chain_depth[u] < chain_depth[v]) swap(u, v);
		seg_update(1, 0, leaf_size-1, chain_index[chain_num[u]], chain_index[u], diff);
		u = par[chain_num[u]];
	}
	if (chain_index[u] > chain_index[v]) swap(u, v);
	seg_update(1, 0, leaf_size-1, chain_index[u] + 1, chain_index[v], diff);
}

ll query_getsum(int u, int v){
	ll ret = 0;
	while(chain_num[u] != chain_num[v]){
		if (chain_depth[u] < chain_depth[v]) swap(u, v);
		ret += seg_getsum(1, 0, leaf_size-1, chain_index[chain_num[u]], chain_index[u]);
		u = par[chain_num[u]];
	}
	if (chain_index[u] > chain_index[v]) swap(u, v);	
	ret += seg_getsum(1, 0, leaf_size-1, chain_index[u] + 1, chain_index[v]);
	return ret;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
//	scanf("%d %d\n", &N, &M);
	for (int i=0;i<N-1;i++){
		int u, v;
		cin >> u >> v;
//		scanf("%d %d\n", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs_sz_and_par(1, 0);
	HLD(1, 0, 1, 0);
	
	for (int i=0;i<M;i++){
		char op;
		int u, v;
		cin >> op >> u >> v;
//		cout << op << " " << u << " " << v << endl;
//		scanf("%c %d %d\n", op, u, v);
		if (op == 'P'){
			query_update(u, v, 1);
		}
		else{
			cout << query_getsum(u, v) << "\n";
		}
	}
	
	
	return 0;
}


