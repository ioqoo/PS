#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N, Q;
vector<ll> nums;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int s, int e){
    if (s == e) return tree[node] = arr[s];

    int mid = (s+e) / 2;

    return tree[node] = init(arr, tree, node*2, s, mid) + init(arr, tree, node*2+1, mid+1, e);
}

void update(vector<ll> &tree, int node, int s, int e, int ind, ll diff){
    if (!(s <= ind && ind <= e)) return;

    tree[node] += diff;

    if (s != e){
        int mid = (s+e)/2;
        update(tree, node*2, s, mid, ind, diff);
        update(tree, node*2 + 1, mid+1, e, ind, diff);
    }
}

ll sum(vector<ll> &tree, int node, int s, int e, int l, int r){
    if (e < l || r < s) return 0;

    if (l <= s && e <= r) return tree[node];

    int mid = (s+e)/2;
    return sum(tree, node*2, s, mid, l, r) + sum(tree, node*2+1, mid+1, e, l, r);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &Q);
    for (int i=0;i<N;i++){
        ll temp;
        scanf("%lld", &temp);
        nums.push_back(temp);
    }
    int tree_size = 1 << ((int)ceil(log2(N)+1));
    vector<ll> segtree(tree_size);
    init(nums, segtree, 1, 0, N-1);

    for (int i=0;i<Q;i++){
        int x, y;
        int a;
        ll b;
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        if (x > y) {
            int temp = y;
            y = x;
            x = temp;
        }
        printf("%lld\n", sum(segtree, 1, 0, N-1, x-1, y-1));
        update(segtree, 1, 0, N-1, a-1, b - nums[a-1]);
        nums[a-1] = b;
    }

    return 0;
}
