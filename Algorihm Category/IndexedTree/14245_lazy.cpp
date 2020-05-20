#include <iostream>
#include <cmath>

const int MAX = 1 << ((int)ceil(log2(500000))+1);

using namespace std;

int N, M, leaf_size;
int tree[MAX];
int lazy[MAX];

void init(){
    for (int i=leaf_size-1;i>0;i--){
        tree[i] = tree[i*2] ^ tree[i*2+1];
    }
}

void prop(int node, int l, int r){
    if (lazy[node] != 0){
        if (node < leaf_size){
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        else tree[node] ^= lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int s, int e, int diff){
    prop(node, l, r);
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        lazy[node] ^= diff;
        prop(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node*2, l, mid, s, e, diff);
    update(node*2+1, mid+1, r, s, e, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int getxor(int node, int l, int r, int s, int e){
    prop(node, l, r);
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return tree[node];
    int mid = (l + r) / 2;
    return getxor(node*2, l, mid, s, e) ^ getxor(node*2+1, mid+1, r, s, e);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    leaf_size = 1 << ((int)ceil(log2(N)));
    for (int i=0;i<N;i++){
        scanf("%d", &tree[i+leaf_size]);
    }
    init();
    scanf("%d", &M);
    int op, a, b, c;
    for (int i=0;i<M;i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %d %d", &a, &b, &c);
            update(1, 0, leaf_size-1, a, b, c);
        }
        else{
            scanf("%d", &a);
            printf("%d\n", getxor(1, 0, leaf_size-1, a, a));
        }
    }
    

    return 0;
}



