#include <bits/stdc++.h>
const int INF = 1e9+7;
const int NMAX = 100005;
const int MAX = 1 << (int)(ceil(log2(NMAX))+1);
using namespace std;

int N, K, leaf_size;
int maxtree[MAX];
int mintree[MAX];
int dvd[NMAX];

void init(){
	for (int i=leaf_size;i<leaf_size*2;i++){
		maxtree[i] = i-leaf_size;
		mintree[i] = i-leaf_size;
	}
	for (int i=leaf_size-1;i>=1;i--){
		maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
		mintree[i] = min(mintree[i*2], mintree[i*2+1]);
	}
}

void update(int pos, int diff){
	int maxpos = pos + leaf_size;
	maxtree[maxpos] = diff;
	while(maxpos > 1){
		maxpos /= 2;
		maxtree[maxpos] = max(maxtree[maxpos*2], maxtree[maxpos*2+1]);
	}
	int minpos = pos + leaf_size;
	mintree[minpos] = diff;
	while(minpos > 1){
		minpos /= 2;
		mintree[minpos] = min(mintree[minpos*2], mintree[minpos*2+1]);
	}
}

int getmin(int node, int l, int r, int s, int e){
	if (r < s || e < l) return INF;
	if (s <= l && r <= e) return mintree[node];
	int mid = (l+r) / 2;
	return min(getmin(node*2, l, mid, s, e), getmin(node*2+1, mid+1, r, s, e));
}

int getmax(int node, int l, int r, int s, int e){
	if (r < s || e < l) return -1;
	if (s <= l && r <= e) return maxtree[node];
	int mid = (l+r) / 2;
	return max(getmax(node*2, l, mid, s, e), getmax(node*2+1, mid+1, r, s, e));
}

void solve(){
	scanf("%d %d", &N, &K);
	leaf_size = 1 << (int)ceil(log2(N));
	memset(mintree, 0x3f, sizeof(mintree));
	memset(maxtree, -1, sizeof(maxtree));
	for (int i=0;i<N;i++){
		dvd[i] = i;
	}
	init();
	for (int i=0;i<K;i++){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
//		a--; b--;
		if (op == 0){
			swap(dvd[a], dvd[b]);
			update(a, dvd[a]);
			update(b, dvd[b]);
		}
		else if (op == 1){
			int cmin = getmin(1, 0, leaf_size-1, a, b);
			int cmax = getmax(1, 0, leaf_size-1, a, b);
			if (cmin == a && cmax == b) printf("YES\n");
			else printf("NO\n");
		}
	}
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--) solve();
	
	return 0;
}


