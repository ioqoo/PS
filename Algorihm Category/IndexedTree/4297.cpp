#include <bits/stdc++.h>
#define ll long long
const int NMAX = 500003;
const int MAX = 1 << (int)(ceil(log2(NMAX))+1);
using namespace std;

int tree[MAX], leaf_size;

void update(int pos, int val){
	pos += leaf_size;
	tree[pos] += val;
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
	
	while(1){
		memset(tree, 0, sizeof(tree));
		int N;
		scanf("%d", &N);
		if (N==0) return 0;
		leaf_size = 1 << (int)ceil(log2(N));
		vector<int> arr;
		vector<int> compress;
		for (int i=0;i<N;i++){
			int temp;
			scanf("%d", &temp);
			arr.push_back(temp);
			compress.push_back(temp);
		}
		sort(compress.begin(), compress.end());
		compress.erase(unique(compress.begin(), compress.end()), compress.end());
		for (int i=0;i<N;i++){
			int curr = arr[i];
			int pos = lower_bound(compress.begin(), compress.end(), curr) - compress.begin();
			arr[i] = pos;
		}
		ll ans = 0;
		for (int i=0;i<N;i++){
			ans += (ll)getsum(1, 0, leaf_size-1, arr[i]+1, N-1);
			update(arr[i], 1);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}


