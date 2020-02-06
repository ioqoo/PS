#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define piii pair<pair<int, int>, int>
#define pddi pair<pair<double, double>, int>
#define plll pair<pair<ll, ll>, ll>
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpdd vector<pdd>
#define fi first
#define se second
#define INF 1000000000000000000LL
#define MAX 1234567890

using namespace std;

int arr[100001];
int tree[400004];
int n, m;


int init(int node, int start, int end){
	if (start==end) return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min(init(node*2, start, mid), init(node*2 + 1, mid+1, end));
}

void update(int node, int start, int end, int index, int val){
	if (!(start<=index && index<=end)) return;

	tree[node] = min(tree[node], val);

	if (start!=end){
		int mid = (start + end) / 2;
		update(node*2, start, mid, index, val);
		update(node*2 + 1, mid+1, end, index, val);
	}
}

int get_min(int node, int start, int end, int left, int right){
	if (left > end || right < start) return MAX;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(get_min(node*2, start, mid, left, right), get_min(node*2+1, mid+1, end, left, right));
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int tree_size = 1 << ((int)ceil(log2(n)) + 1);
	fill(tree+1, tree+tree_size+1, MAX);
	init(1, 0, n-1);
	// for (int i=1;i<=tree_size;i++){
	// 	printf("%d ", tree[i]);
	// }
	// printf("\n");
	for (int i=0;i<m;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", get_min(1, 0, n-1, a-1, b-1));
	}
}

