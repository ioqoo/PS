#include <bits/stdc++.h>
#define MAX 5000005
#define INF 2000000000LL
#define ll long long

using namespace std;

int N, L;
int tree_size;
vector<ll> arr(MAX);

ll init(vector<ll> &arr, vector<ll> &tree, int node, int s, int e){
	if (s == e) tree[node] = arr[s];
	
	int mid = (s+e)/2;
	
	return tree[node] = min(init(arr, tree, node*2, s, mid), init(arr, tree, node*2+1, mid+1, e));
}

ll get_min(vector<ll> &tree, int node, int s, int e, int l, int r){
	if (e < l || r < s) return INF;
	
	else if (l <= s && e <= r) return tree[node];
	
	int mid = (s+e)/2;
	
	return min(get_min(tree, node*2, s, mid, l, r) , get_min(tree, node*2+1, mid+1, e, l, r));
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &L);
    
    for (int i=0;i<N;i++){
    	printf("%lld", arr[i]);
	}
	
	tree_size = 1 << ((int)ceil(log2(MAX)+1));
	vector<ll> segtree(tree_size);
	
	init(arr, segtree, 1, 0, MAX-1);
	
	for (int i=0;i<N;i++){
		int left = max(0, i-L);
		printf("%lld ", get_min(segtree, 1, 0, MAX-1, left, i));
	}

    return 0;
}
