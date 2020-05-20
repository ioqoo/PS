#include <iostream>
#include <cmath>

const int MAX = 1 << ((int)ceil(log2(100000))+1);

using namespace std;

int N, M, leaf_size;
int tree[MAX];
bool lazy[MAX];

void prop(int node, int l, int r){
    if (lazy[node]){
        if (node < leaf_size){
            lazy[node*2] ^= 1; // toggle
            lazy[node*2+1] ^= 1;
            
            int lc = 0, rc = 0;
            int mid = (l+r) / 2;
            if (lazy[node*2]) lc = (mid-l+1) - tree[node*2];
            else lc = tree[node*2];
            if (lazy[node*2+1]) rc = (r-mid) - tree[node*2+1];
            else rc = tree[node*2+1];
            
            tree[node] = lc + rc;
        }
        else tree[node] ^= 1;
        
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int s, int e){
    prop(node, l, r);
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        lazy[node] ^= 1;
        prop(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node*2, l, mid, s, e);
    update(node*2+1, mid+1, r, s, e);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int sum(int node, int l, int r, int s, int e){
    prop(node, l, r);
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return tree[node];
    int mid = (l + r)/2;
    return sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e);
}

void debug(){
    for (int i=1;i<leaf_size*2;i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    leaf_size = 1 << ((int)ceil(log2(N)));
    
    int op, a, b;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &op, &a, &b);
        a--; b--;
        if (op == 0){
            update(1, 0, leaf_size-1, a, b);
        }
        else printf("%d\n", sum(1, 0, leaf_size-1, a, b));        
    }

    return 0;
}



