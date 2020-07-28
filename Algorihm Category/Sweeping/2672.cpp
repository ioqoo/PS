#include <bits/stdc++.h>
const int MAX = 20005;
using namespace std;

struct edge{
	int x, y1, y2;
	bool is_start;
	edge (int a, int b, int c, bool d){
		x = a;
		y1 = b;
		y2 = c;
		is_start = d;
	}
	
	bool operator < (edge& b){
		return x < b.x;
	}
};

int N;
vector<edge> E;
int tree[4*MAX];
int cnt[4*MAX];

void update(int node, int l, int r, int s, int e, int diff){
	if (r < s || e < l) return;
	if (s <= l && r <= e) cnt[node] += diff;
	else{
		int mid = (l + r) / 2;
		update(node*2, l, mid, s, e, diff);
		update(node*2+1, mid+1, r, s, e, diff);
	}
	if (cnt[node] > 0) tree[node] = (r-l+1);
	else{
		if (l == r) tree[node] = 0;
		else tree[node] = tree[node*2] + tree[node*2+1];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	int leaf_size = 2*MAX;
	double x1, y1, x2, y2;
	for (int i=0;i<N;i++){
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		int a = (x1*10) + 1e-6;
		int b = (y1*10) + 1e-6;
		int c = (x2*10) + 1e-6;
		int d = (y2*10) + 1e-6;
		E.push_back({a, b, b+d, true});
		E.push_back({a+c, b, b+d, false});
	}
	
	sort(E.begin(), E.end());
	
	int ans = 0;
	edge prev = E[0];
	for (int i=0;i<2*N;i++){
		auto curr = E[i];
		if (i==0) {
			prev = curr;
			update(1, 0, leaf_size-1, curr.y1, curr.y2-1, 1);
		}
		else{
			int cnt = tree[1];
			ans += (curr.x - prev.x) * cnt;
			if (curr.is_start){
				update(1, 0, leaf_size-1, curr.y1, curr.y2-1, 1);
			}
			else{
				update(1, 0, leaf_size-1, curr.y1, curr.y2-1, -1);
			}
			prev = curr;
		}
	}
	if (ans % 100 == 0) printf("%d\n", ans/100);
	else printf("%.2lf\n", ans / 100.0);
	
	
	
	
	return 0;
}


