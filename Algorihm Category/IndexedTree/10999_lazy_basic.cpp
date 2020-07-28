#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define MAX 1000005

int N, M, K, leaf_size;
ll tree[1<<21], lazy[1<<21];

void init() {
	for (int i=leaf_size-1; i>0; i--) {
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}


void prop(int node, int l, int r) {
	if (lazy[node] != 0) {
		if (node < leaf_size) { // not leaf
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		tree[node] += (r-l+1) * lazy[node];
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int s, int e, ll k) {
	prop(node, l, r);

	if (r < s || e < l) return;
	if (s <= l && r <= e) {
		lazy[node] += k;
		prop(node, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(node*2, l, mid, s, e, k);
	update(node*2+1, mid+1, r, s, e, k);

	tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(int node, int l, int r, int s, int e) {
	prop(node, l, r);

	if (r < s || e < l) return 0LL;
	if (s <= l && r <= e) return tree[node];
	int mid = (l + r) / 2;
	return sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d %d", &N, &M, &K);
	leaf_size = 1 << ((int)ceil(log2(N)));

	ll temp;
	for (int i=0; i<N; i++) {
		scanf("%lld", &temp);
		tree[i+leaf_size] = temp;
	}
	init();

	int op, b, c;
	ll d;
	for (int i=0; i<M+K; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d %lld", &b, &c, &d);
			b--;
			c--;
			update(1, 0, leaf_size-1, b, c, d);
		} else {
			scanf("%d %d", &b, &c);
			b--;
			c--;
			printf("%lld\n", sum(1, 0, leaf_size-1, b, c));
		}

	}

	return 0;
}



