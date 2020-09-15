#include <bits/stdc++.h>
const int NMAX = 1000005;
const int TMAX = 1 << (int)(ceil(log2(NMAX))+1);
using namespace std;

struct edge{
	int x, y1, y2;
	int is_start;
	bool operator < (edge B){
		if (x == B.x) return is_start < B.is_start;
		return x < B.x;
	}
};

int lib_x1, lib_x2, lib_y1, lib_y2; 
int K; // carpet edge length
int M; // stain cnt
int sumtree[TMAX], maxtree[TMAX];
vector<edge> E;

void update(int node, int l, int r, int s, int e, int diff){
	if (r < s || e < l) return;
	if (s <= l && r <= e) sumtree[node] += diff;
	else{
		int mid = (l + r) / 2;
		update(node*2, l, mid, s, e, diff);
		update(node*2+1, mid+1, r, s, e, diff);
	}
	if (l == r) maxtree[node] = sumtree[node];
	else maxtree[node] = sumtree[node] + max(maxtree[node*2], maxtree[node*2+1]);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int leaf_size = TMAX / 2;
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	lib_x1 = a, lib_y2 = b, lib_x2 = c, lib_y1 = d;
	scanf("%d %d", &K, &M);
	for (int i=0;i<M;i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if ((c-a) > K || (b-d) > K) continue;
		E.push_back({max(lib_x1, c-K) - 1, max(lib_y1, b-K), d, 1});
		E.push_back({a, max(lib_y1, b-K), d, -1});
	}
	sort(E.begin(), E.end());
	
	int ans = 0;
	for (auto e: E){
		update(1, lib_y1, lib_y2, e.y1, e.y2, e.is_start);
		ans = max(ans, maxtree[1]);
//		printf("x : %d / y1 : %d / y2 : %d / start : %d / max : %d\n", e.x, e.y1, e.y2, e.is_start, maxtree[1]);
	}
	printf("%d\n", ans);
	
	
	
	return 0;
}


