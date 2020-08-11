#include <bits/stdc++.h>
#define ll long long
const int MAX = 1 << (int)ceil(log2(100000)+1);
using namespace std;

struct Node{
	ll val, cnt;
	Node(){
		val = 0;
		cnt = 0;
	}
};

int N, leaf_size;
Node tree[MAX];

void init(){
	for (int i=leaf_size-1;i>=1;i--){
		tree[i].val = tree[i*2].val + tree[i*2+1].val;
	}
}

void update(int node, int l, int r, int s, int e){
	if (r < s || e < l) return;
	
	if (s <= l && r <= e) {
		tree[node].val += (ll)(l - s + 1);
		tree[node].cnt++;
	}
	else{
		int mid = (l + r) / 2;
		update(node*2, l, mid, s, e);
		update(node*2+1, mid+1, r, s, e);
	}
}

ll sum(int node, int l, int r, int d){
	if (r < d || d < l) return 0LL;
	
	if (l == r) return tree[node].val;
	
	int mid = (l + r) / 2;
	return sum(node*2, l, mid, d) + sum(node*2+1, mid+1, r, d) + tree[node].val + tree[node].cnt * (d - l);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		ll temp;
		scanf("%lld", &temp);
		tree[i+leaf_size].val = temp;
	}
//	init();
	
	int Q;
	scanf("%d", &Q);
	for (int i=0;i<Q;i++){
		int op;
		scanf("%d", &op);
		if (op == 1){
			int l, r;
			scanf("%d %d", &l, &r);
			l--; r--;
			update(1, 0, leaf_size-1, l, r);
		}
		else{
			int x;
			scanf("%d", &x);
			x--;
			printf("%lld\n", sum(1, 0, leaf_size-1, x));
		}
	}
	
	return 0;
}

