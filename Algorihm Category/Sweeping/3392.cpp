#include <bits/stdc++.h>

const int MAX = 30005;
using namespace std;

struct edge{
	int x, y1, y2;
	bool is_start;
	edge(int a, int b, int c, bool d){
		x = a;
		y1 = b;
		y2 = c;
		is_start = d;
	}
	bool operator < (const edge &b) const {
		return x < b.x;
	}
};

int N, leaf_size;
vector<edge> E;
int tree[4*MAX];
int cnt[4*MAX];
// cnt[i] : positive if every child of node i is positive

void update(int node, int l, int r, int s, int e, int diff){
	if (r < s || e < l) return;
	if (s <= l && r <= e) cnt[node] += diff;
	else{
		int mid = (l+r) / 2;
		update(node*2, l, mid, s, e, diff);
		update(node*2+1, mid+1, r, s, e, diff);
	}
	if (cnt[node] > 0) tree[node] = r-l+1;
	else {
		if (l == r) tree[node] = 0;
		else tree[node] = tree[node*2] + tree[node*2+1];
	}
	
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	leaf_size = 1 << ((int)ceil(log2(MAX)));
	for (int i=0;i<N;i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		E.push_back({x1, y1, y2-1, true});
		E.push_back({x2, y1, y2-1, false});
	}
	sort(E.begin(), E.end());
	int ans = 0;
	auto pre = E[0];
	update(1, 0, leaf_size-1, pre.y1, pre.y2, 1);
	for (int i=1;i<2*N;i++){
		auto curr = E[i];
		int dx = curr.x - pre.x;
		int cnt = tree[1];
		ans += dx * cnt;
		if (curr.is_start) update(1, 0, leaf_size-1, curr.y1, curr.y2, 1);
		else update(1, 0, leaf_size-1, curr.y1, curr.y2, -1);
		pre = curr;
	}
	printf("%d\n", ans);
		
	
	return 0;
}


