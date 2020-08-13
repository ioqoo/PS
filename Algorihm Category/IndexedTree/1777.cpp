#include <bits/stdc++.h>
const int NMAX = 100005;
const int MAX = 1 << (int)(ceil(log2(NMAX))+1);
using namespace std;

int N, leaf_size;
int arr[MAX], tree[MAX];

void init(){
	for (int i=leaf_size-1;i>=1;i--){
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}

void update(int pos, int diff){
	pos += leaf_size;
	tree[pos] = diff;
	while(pos > 1){
		pos /= 2;
		tree[pos] = tree[pos*2] + tree[pos*2+1];
	}
}

int get_rank(int node, int l, int r, int remain){
	if (l == r) return l;
	int lc = tree[node*2];
	int mid = (l+r) / 2;
	if (remain < lc){
		return get_rank(node*2, l, mid, remain);
	}
	else{
		return get_rank(node*2+1, mid+1, r, remain - lc);
	}
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		tree[i+leaf_size] = 1;
	}
	init();
	
	for (int i=0;i<N;i++){
		scanf("%d", &arr[i]);
	}
	
	vector<int> ans(N);
	for (int i=N-1;i>=0;i--){
		int curr_rank = arr[i];
		int curr_pos = get_rank(1, 0, leaf_size-1, curr_rank);
//		printf("%d\n", curr_pos);
		ans[curr_pos] = i+1;
		update(curr_pos, 0);
//		for (int i=1;i<leaf_size*2;i++){
//			printf("%d ", tree[i]);
//		}
//		printf("\n");
	}
	reverse(ans.begin(), ans.end());
	for (int n: ans){
		printf("%d ", n);
	}
	
	
	
	return 0;
}


