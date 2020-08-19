#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
const int NMAX = 250005;
const int MAX = 1 << (int)(ceil(log2(NMAX)) + 1);
using namespace std;

int N, M, leaf_size;
int tree[MAX][10], lazy[MAX], temp[10];
int arr[MAX];

void init(int pos, int digit){
	pos += leaf_size;
	tree[pos][digit]++;
	while(pos > 1){
		pos /= 2;
		tree[pos][digit] = tree[pos*2][digit] + tree[pos*2+1][digit];
	}
}

void prop(int node, int l, int r){
	if (lazy[node] == 0) return;
	if (l != r){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	for (int i=0;i<10;i++){
		temp[(i+lazy[node])%10] = tree[node][i];
	}
	for (int i=0;i<10;i++){
		tree[node][i] = temp[i];
	}
	lazy[node] = 0;
}

void update(int node, int l, int r, int s, int e){
	prop(node, l, r);
	if (r < s || e < l) return;
	if (s <= l && r <= e){
		lazy[node]++;
		prop(node, l, r);
		return;
	}
	int mid = (l+r) / 2;
	update(node*2, l, mid, s, e);
	update(node*2+1, mid+1, r, s, e);
	for (int i=0;i<10;i++){
		tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
	}
}

int sum(int node, int l, int r, int s, int e){
	prop(node, l, r);
	if (r < s || e < l) return 0;
	if (s <= l && r <= e){
		int ret = 0;
		for (int i=0;i<10;i++){
			ret += tree[node][i] * i;
		}
		return ret;
	}
	int mid = (l+r) / 2;
	return sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &M);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		int val;
		scanf("%1d", &val);
		init(i, val);
	}
	for (int i=0;i<M;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		printf("%lld\n", (ll)sum(1, 0, leaf_size-1, a, b));
		update(1, 0, leaf_size-1, a, b);
	}	
	
	
	return 0;
}


