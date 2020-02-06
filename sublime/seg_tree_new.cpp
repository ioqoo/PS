#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define INF 1000000000000000000LL
#define MAX 987654321
using namespace std;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
	if (start==end) return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2 + 1, mid + 1, end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	// diff : index번째 원소를 바꿨을때의 변화량
	if (!(start<=index && index<=end)) return;

	tree[node] += diff;

	if (start!=end){
		int mid = (start + end) / 2;
		update(tree, node*2, start, mid, index, diff);
		update(tree, node*2 + 1, mid + 1, end, index, diff);
	}
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	// left, right : 합을 구하고자 하는 범위
	// start, end : 현재 탐색 중인 범위
	
	if (left > end || right < start) return 0;
	// 현재 탐색 중인 범위가 구하려는 범위와 아예 관계 없는 경우

	if (left <= start && end <= right) return tree[node];
	// 현재 탐색 중인 범위가 구하려는 범위에 완전히 포함된 경우
	
	// 이 외의 경우엔 반으로 쪼개서 재귀로 다시 탐색
	int mid = (start+end) / 2;
	return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2 + 1 , mid + 1 , end, left, right);

}

int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	int tree_size = (1 << ((int)ceil(log2(N)) + 1));
	vll seg_tree(tree_size);
	for (int x=0;x<Q;x++){
		int op;
		scanf("%d", &op);
		if (op==1) {
			int p;
			ll x;
			scanf("%d %lld", &p, &x);
			update(seg_tree, 1, 0, N-1, p-1, x);
		}
		else {
			int p, q;
			scanf("%d %d", &p, &q);
			printf("%lld", sum(seg_tree, 1, 0, N-1, p-1, q-1));
		}
	}
}

