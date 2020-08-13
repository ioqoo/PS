#include <bits/stdc++.h>
const int NMAX = 250005;
const int MAX = 1 << (int)(ceil(log2(NMAX)) + 1);
using namespace std;

int N, M, leaf_size;
int tree[MAX];

void init(){
	for (int i=leaf_size-1;i>=1;i--){
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}

void update(int pos, int val){
	pos += leaf_size;
	tree[pos] = val;
	while(pos > 1){
		pos /= 2;
		tree[pos] = tree[pos*2] + tree[pos*2+1];
	}
}

int getsum(int node, int l, int r, int s, int e){
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return tree[node];
	int mid = (l+r) / 2;
	return getsum(node*2, l, mid, s, e) + getsum(node*2+1, mid+1, r, s, e);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &M);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		scanf("%1d", &tree[i+leaf_size]);
	}
	init();
	for (int i=0;i<M;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		printf("%d\n", getsum(1, 0, leaf_size-1, a, b));
		int a_val = tree[a + leaf_size];
		int b_val = tree[b + leaf_size];
		update(a, (a_val+1)%10);
		update(b, (b_val+1)%10);
	}
	
	
	
	return 0;
}


