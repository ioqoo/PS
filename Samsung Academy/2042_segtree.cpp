#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N, M, K;
vector<ll> nums;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int s, int e){
    if (s == e) return tree[node] = arr[s];

    int mid = (s + e) / 2;

    return tree[node] = init(arr, tree, node*2, s, mid) + init(arr, tree, node*2 + 1, mid+1, e);
}

void update(vector<ll> &tree, int node, int s, int e, int ind, ll diff){
    // starts from root
    if (!(s<=ind && ind<=e)) return;

    tree[node] += diff;

    if (s != e){
        int mid = (s+e) / 2;
        update(tree, node*2, s, mid, ind, diff);
        update(tree, node*2+1, mid+1, e, ind, diff);
    }
}

ll sum(vector<ll> &tree, int node, int s, int e, int l, int r){
    // l, r : 목표
    // s, e : 현재

    // 1. 아예 밖일 때
    if (e < l || r < s) return 0;

    // 2. 완전히 포함
    if (l <= s && e <= r) return tree[node];

    int mid = (s+e) / 2;
    return sum(tree, node*2, s, mid, l, r) + sum(tree, node*2+1, mid+1, e, l, r);


}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0;i<N;i++){
        int n;
        scanf("%d", &n);
        nums.push_back(n);
    }
    int tree_size = 1 << ( (int)ceil(log2(N) + 1) );
    vector<ll> segtree(tree_size);
    init(nums, segtree, 1, 0, N-1);
//    for (auto n: segtree){
//        printf("%lld ", n);
//    }


    for (int i=0;i<M+K;i++){
        int op;
        scanf("%d", &op);
        if (op == 1){
            int b;
            ll c;
            scanf("%d %lld", &b, &c);
            update(segtree, 1, 0, N-1, b-1, c - nums[b-1]);
            nums[b-1] = c;
        }
        else{
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(segtree, 1, 0, N-1, b-1, c-1));
        }
    }

    return 0;
}
