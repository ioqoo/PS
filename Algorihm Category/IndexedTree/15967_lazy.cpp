#include <iostream>
#include <cmath>

#define ll long long
const int MAX = 1 << ((int)ceil(log2(1000000))+1);

using namespace std;

int N, Q1, Q2, leaf_size;
ll tree[MAX];
ll lazy[MAX];

void init(){
    for (int i=leaf_size-1;i>0;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void prop(int node, int l, int r){
    if (lazy[node] != 0){
        if (node < leaf_size){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node] += (r-l+1) * lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int s, int e, ll diff){
    prop(node, l, r);
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        lazy[node] += diff;
        prop(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node*2, l, mid, s, e, diff);
    update(node*2+1, mid+1, r, s, e, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(int node, int l, int r, int s, int e){
    prop(node, l, r);
    if (r < s || e < l) return 0LL;
    if (s <= l && r <= e) return tree[node];
    int mid = (l + r) / 2;
    return sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e);
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d %d", &N, &Q1, &Q2);
    leaf_size = 1 << ((int)ceil(log2(N)));
    for (int i=0;i<N;i++){
        scanf("%d", &tree[i+leaf_size]);
    }
    init();
    
    int op, a, b;
    ll d;
    for (int i=0;i<Q1+Q2;i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %d", &a, &b);
            a--; b--;
            printf("%lld\n", sum(1, 0, leaf_size-1, a, b));
        }
        else{
            scanf("%d %d %lld", &a, &b, &d);
            a--; b--;
            update(1, 0, leaf_size-1, a, b, d);
        }
    }

    return 0;
}



