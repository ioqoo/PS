#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define MyMax(a, b) (a)>(b)?(a):(b)

int N;
int leaf_size;
int arr[100005];
int tree[400444];
int idx[100005];

bool cmp (int a, int b) {
	if (arr[a]==arr[b]) {
		return a>b;
	}
	return arr[a]<arr[b];
}

int init(int node, int st, int end) {
	if (st==end) {
		return tree[node] = arr[st];
	}

	return tree[node] = MyMax(init(node*2, st, (st+end)/2), init(node*2+1, (st+end)/2+1, end));
}

int find_max(int node, int st, int end, int left, int right) {
	if (end<left || right<st) return -1;
	if (left<=st && end<=right) return tree[node];

	return MyMax(find_max(node*2, st, (st+end)/2, left, right), find_max(node*2+1, (st+end)/2+1, end, left, right));
}

int update(int ind, int val){
    ind += leaf_size;
    tree[ind] = val;
    while(ind > 1){
        ind /= 2;
        tree[ind] = MyMax(tree[ind*2], tree[ind*2+1]);
    }
}

//int update(int node, int st, int end, int ind, int val) {
//	if (ind<st || end<ind) return -1;
//	if (st==end) {
//		return tree[node] = val;
//	}
//
//	tree[node] = MyMax(tree[node], update(node*2, st, (st+end)/2, ind, val));
//	tree[node] = MyMax(tree[node], update(node*2+1, (st+end)/2+1, end, ind, val));
//	return tree[node];
//}

void input() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		idx[i] = i;
	}
	sort(idx, idx+N, cmp);
	for (int i=0; i<N; i++) {
		arr[i] = 0;
	}
}

void clear() {
    memset(tree, 0, sizeof(tree));
    memset(idx, 0, sizeof(idx));
    memset(arr, 0, sizeof(arr));
}


int main () {
    freopen("input.txt", "r", stdin);
	while (scanf("%d", &N) != EOF) {
	    leaf_size = 1 << (int)(ceil(log2(N)));
        for (int i=0; i<N; i++) {
            scanf("%d", &arr[i]);
            idx[i] = i;
        }
        sort(idx, idx+N, cmp);
        for (int i=0; i<N; i++) {
            arr[i] = 0;
        }
        /*for (int i=0; i<N; i++) {
			printf("%d ", idx[i]);
		}*/
		for (int i=0, x; i<N; i++) {
			x = find_max(1, 0, N-1, 0, idx[i]);
			x += 1;
			update(idx[i], x);
//			update(1, 0, N-1, idx[i], x);
		}
		printf("%d\n", tree[1]);
		clear();
	}
	return 0;
}
