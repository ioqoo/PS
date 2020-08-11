#include <bits/stdc++.h>
typedef long long ll;
const int NMAX = 200005;
const int MAX = 1 << (int)(ceil(log2(NMAX))+1);
const ll MOD = 1e9+7;
using namespace std;

int N, M, C, leaf_size;
vector<int> graph[NMAX];
vector<int> tree[MAX];
int color[NMAX];
bool visited[NMAX];
int st[NMAX], en[NMAX];
int piv;

void init(){
	for (int i=leaf_size-1;i>=1;i--){
		vector<int> &c = tree[i], &l = tree[i*2], &r = tree[i*2+1];
		c.resize(l.size() + r.size());
		for (int j=0, p=0, q=0;j<c.size();j++){
			if (q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
			else c[j] = r[q++];
		}
	}
}

int getans(int node, int l, int r, int s, int e, int k){
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) {
		return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	}
	int mid = (l + r) / 2;
	return getans(node*2, l, mid, s, e, k) + getans(node*2+1, mid+1, r, s, e, k);
}

void dfs(int curr){
	st[curr] = piv++;
	visited[curr] = true;
	for (int next: graph[curr]){
		if (visited[next]) continue;
		dfs(next);
	}
	en[curr] = piv-1;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d %d", &N, &M, &C);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		scanf("%d", &color[i]);
	}
	
	for (int i=0;i<N-1;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	
	for (int i=0;i<N;i++){
		tree[st[i] + leaf_size].push_back(color[i]);
	}
	
	init();
	ll ans = 0;
	for (int i=0;i<M;i++){
		int v, c;
		scanf("%d %d", &v, &c);
		v--;
		ans = (ans + (ll)getans(1, 0, leaf_size-1, st[v], en[v], c)) % MOD;
//		printf("%d %d\n", st[v], en[v]);
	}
	printf("%lld\n", ans);
	
	
	
	return 0;
}


