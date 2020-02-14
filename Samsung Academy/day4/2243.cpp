#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000

using namespace std;

int N;
int tree_size;

//void init(vector<ll> &arr, vector<ll> &tree, int node, int s, int e){
//	if (s == e) tree[node] = arr[s];
//	
//	int mid = (s+e) / 2;
//	
//	return tree[node] = init(arr, tree, node*2, s, mid) + init(arr, tree, node*2 + 1, mid+1, e);
//}

void update(vector<ll> &tree, int node, int s, int e, int ind, ll diff){
	if (!(s<=ind && ind<=e)) return;
	
	tree[node] += diff;
	
	if (s != e){
		int mid = (s+e) / 2;
		update(tree, node*2, s, mid, ind, diff);
		update(tree, node*2+1, mid+1, e, ind, diff);
	}
}

//ll sum(vector<ll> &tree, int node, int s, int e, int l, int r){
//	if (e < l || r < s) return 0LL;
//	
//	else if (l <= s && e <= r) return tree[node];
//	
//	int mid = (s+e)/2;
//	
//	return sum(tree, node*2, s, mid, l, r) + sum(tree, node*2+1, mid+1, e, l, r);
//}

int find(vector<ll> &tree, int node, int s, int e, ll remain){
//	printf("%d %d %lld %lld\n", s, e, tree[node], remain);
	if (s==e) return s;
	
	int left = node*2;
	int right = node*2+1;
	
	int mid = (s+e) / 2;
	
	if ((left <= tree_size) && (tree[left] >= remain)) {
		return find(tree, node*2, s, mid, remain);
	}
	else if ( (right <= tree_size) && (tree[left] < remain) ){
		return find(tree, node*2+1, mid+1, e, remain - tree[left]);
	}
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	tree_size = 4 * MAX;
	vector<ll> segtree(tree_size);
	
	for (int i=0;i<N;i++){
		int op;
		scanf("%d", &op);
		if (op == 2){
			int b;
			ll c;
			scanf("%d %lld", &b, &c);
			b--;
			update(segtree, 1, 0, MAX-1, b, c);
		}
		else{
			ll b;
			scanf("%lld", &b);
			int pos = find(segtree, 1, 0, MAX-1, b);
			printf("%d\n", pos+1);
			update(segtree, 1, 0, MAX-1, pos, -1LL);
		}
	}

	return 0;
}
