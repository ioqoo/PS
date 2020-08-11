#include <bits/stdc++.h>
const int NMAX = 100005;
const int MAX = 1 << (int)(ceil(log2(NMAX)) + 1);
using namespace std;

int N, M, leaf_size;
vector<int> tree[MAX];

void init(){
	for (int i=leaf_size-1;i>=1;i--){
		vector<int> &c = tree[i], &l = tree[i*2], &r = tree[i*2+1];
		c.resize(l.size() + r.size());
		for (int j=0,p=0,q=0;j<c.size();j++){
			if (q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
			else c[j] = r[q++];
		}
	}
}

int getans(int node, int l, int r, int s, int e, int k){
	if (r < s || e < l) return 0;
	if (s <= l && r <= e){
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	}
	int mid = (l + r) / 2;
	return getans(node*2, l, mid, s, e, k) + getans(node*2+1, mid+1, r, s, e, k);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		tree[i+leaf_size].push_back(temp);
	}
	init();
	scanf("%d", &M);
	int last_ans = 0;
	for (int q=0;q<M;q++){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		i ^= last_ans, j ^= last_ans, k ^= last_ans;
		i--; j--;
		last_ans = getans(1, 0, leaf_size-1, i, j, k);
		printf("%d\n", last_ans);
	}
	
	
	return 0;
}


