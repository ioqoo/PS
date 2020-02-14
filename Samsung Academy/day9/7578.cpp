#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>

#define MAX 500005
#define ll long long

using namespace std;

int N;
int A[MAX], B[MAX];
map<int, int> mapB;

void update(vector<int> &tree, int node, int s, int e, int ind, int diff){
	if (!(s <= ind && ind <= e)) return;
	
	tree[node] += diff;
	
	if (s != e){
		int mid = (s+e) / 2;
		update(tree, node*2, s, mid, ind, diff);
		update(tree, node*2+1, mid+1, e, ind, diff);
	}
}

int get_sum(vector<int> &tree, int node, int s, int e, int l, int r){
	if (e < l || r < s) return 0;
	
	if (l <= s && e <= r) return tree[node];
	
	int mid = (s+e) / 2;
	
	return get_sum(tree, node*2, s, mid, l, r) + get_sum(tree, node*2+1, mid+1, e, l, r);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	
	scanf("%d", &N);
	int tree_size = 1 << ((int)ceil(log2(N))+1);
	vector<int> segtree(tree_size);
	for (int i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		B[i] = temp;
		mapB[temp] = i;
		
	}
	
	
	ll ans = 0LL;
	for (int i=0;i<N;i++){
		int currA_value = A[i];
		int posB = mapB[currA_value];
		update(segtree, 1, 0, N-1, posB, 1);
//		for (int n: segtree){
//			printf("%d ", n);
//		}
//		printf("\n");
		ans += get_sum(segtree, 1, 0, N-1, posB+1, N-1);
	}
	printf("%lld\n", ans);
	
	
	
	
	

    return 0;
}
    
