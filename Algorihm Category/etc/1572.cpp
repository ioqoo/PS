#include <bits/stdc++.h>
#define ll long long
const int NMAX = 65540;
const int MAX = 1 << (int)(ceil(log2(NMAX))+1);
using namespace std;

int N, K, leaf_size;
int tree[MAX];
vector<int> arr;

void update(int i, int val){
	i += leaf_size;
	tree[i] += val;
	while(i > 1){
		i /= 2;
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}

int get_rank(int node, int l, int r, int remain){
	if (l == r) return l;
	int lc = tree[node*2];
	int mid = (l+r) / 2;
	if (remain < lc) return get_rank(node*2, l, mid, remain);
	else return get_rank(node*2+1, mid+1, r, remain - lc);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &K);
	leaf_size = 1 << (int)ceil(log2(NMAX));
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	for (int i=0;i<K-1;i++){
		int temp = arr[i];
		update(temp, 1);
	}
	ll ans = 0;
	for (int i=K-1;i<N;i++){
		int temp = arr[i];
		update(temp, 1);
//		printf("%d\n", get_rank(1, 0, leaf_size-1, (K+1)/2) - 1);
		ans += (ll)get_rank(1, 0, leaf_size-1, (K+1)/2 - 1 );
		update(arr[i-K+1], -1);
	}
	printf("%lld\n", ans);
	
	
	return 0;
}


