#include <iostream>
#include <cmath>

#define ll long long
#define MOD 1000000007
const int MAX = 1 << ((int)ceil(log2(100000)) + 1);

using namespace std;

int N, M, leaf_size;
ll tree[MAX];
ll lazymul[MAX];
ll lazyadd[MAX];

void init(){
    for (int i=leaf_size-1;i>0;i--){
        tree[i] = (tree[i*2] + tree[i*2+1]) % MOD;
    }
}

void prop(int node, int l, int r){
    if (lazymul[node] != 1){
        if (node < leaf_size){
            lazymul[node*2] = (lazymul[node*2] * lazymul[node]) % MOD;
            lazymul[node*2+1] = (lazymul[node*2+1] * lazymul[node]) % MOD;
            lazyadd[node*2] = (lazyadd[node*2] * lazymul[node]) % MOD;
            lazyadd[node*2+1] = (lazyadd[node*2+1] * lazymul[node]) % MOD;
        }
        tree[node] = (lazymul[node] * tree[node]) % MOD;
        lazymul[node] = 1LL;
    }
    if (lazyadd[node] != 0){
        if (node < leaf_size){
            lazyadd[node*2] = (lazyadd[node*2] + lazyadd[node]) % MOD;
            lazyadd[node*2+1] = (lazyadd[node*2+1] + lazyadd[node]) % MOD;
        }
        tree[node] = (tree[node] + (r-l+1)*lazyadd[node]) % MOD;
        lazyadd[node] = 0LL;
    }
}

void updatemul(int node, int l, int r, int s, int e, ll v){
    prop(node, l, r);
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        lazymul[node] = (lazymul[node] * v) % MOD;
        lazyadd[node] = (lazyadd[node] * v) % MOD;
        prop(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    updatemul(node*2, l, mid, s, e, v);
    updatemul(node*2+1, mid+1, r, s, e, v);
    tree[node] = (tree[node*2] + tree[node*2+1]) % MOD;
}

void updateadd(int node, int l, int r, int s, int e, ll v){
    prop(node, l, r);
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        lazyadd[node] = (lazyadd[node] + v) % MOD;
        prop(node, l, r);
        return;
    }    
    int mid = (l + r) / 2;
    updateadd(node*2, l, mid, s, e, v);
    updateadd(node*2+1, mid+1, r, s, e, v);
    tree[node] = (tree[node*2] + tree[node*2+1]) % MOD;    
}

void updateset(int node, int l, int r, int s, int e, ll v){
    prop(node, l, r);
    if (r < s || e < l) return;
    if (s <= l && r <= e){
        lazymul[node] = 0LL;
        lazyadd[node] = v;
        prop(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    updateset(node*2, l, mid, s, e, v);
    updateset(node*2+1, mid+1, r, s, e, v);
    tree[node] = (tree[node*2] + tree[node*2+1]) % MOD;
}

ll sum(int node, int l, int r, int s, int e){
    prop(node, l, r);
    if (r < s || e < l) return 0LL;
    if (s <= l && r <= e) return tree[node];
    int mid = (l + r) / 2;
    return (sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e))%MOD;
}

void debug(){
    for (int i=1;i<leaf_size*2;i++){
        printf("%lld ", tree[i]);
    }
    printf("\n");
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    leaf_size = 1 << ((int)ceil(log2(N)));
    fill(lazymul, lazymul+MAX, 1);
    ll temp;
    for (int i=0;i<N;i++){
        scanf("%lld", &temp);
        tree[i+leaf_size] = temp;
    }
    init();
    
    scanf("%d", &M);
    int op, x, y;
    ll v;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &op, &x, &y);
        x--; y--;
        if (op == 1){
            scanf("%lld", &v);
            updateadd(1, 0, leaf_size-1, x, y, v);
        }
        else if (op == 2){
            scanf("%lld", &v);
            updatemul(1, 0, leaf_size-1, x, y, v);
        }
        else if (op == 3){
            scanf("%lld", &v);
            updateset(1, 0, leaf_size-1, x, y, v);
        }
        else{
            printf("%lld\n", sum(1, 0, leaf_size-1, x, y));
        }
    }

    return 0;
}



