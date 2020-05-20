#include <iostream>
#include <cmath>

#define ll long long

const int MAX = 1 << ((int)ceil(log2(1000000)) + 1);

using namespace std;

int N, M;
ll tree[MAX];
int leaf_size;

void init(){
    for (int i=leaf_size-1;i>0;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(int ind, ll diff){
    ind += leaf_size;
    tree[ind] += diff;
    while(ind > 1){
        ind /= 2;
        tree[ind] = tree[ind*2] + tree[ind*2+1];
    }
}

ll getsum(int node, int l, int r, int s, int e){
    if (r < s || e < l) return 0LL;
    if (s <= l && r <= e) return tree[node];
    int mid = (l+r) / 2;
    return getsum(node*2, l, mid, s, e) + getsum(node*2+1, mid+1, r, s, e);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    leaf_size = 1 << ((int)ceil(log2(N)));
    int op;
    for (int i=0;i<M;i++){
        scanf("%d", &op);
        if (op == 0){
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > b) swap(a, b);
            a--; b--;
            printf("%lld\n", getsum(1, 0, leaf_size-1, a, b));
        }
        else{
            int a;
            ll k;
            scanf("%d %lld", &a, &k);
            a--;
            ll oldval = tree[a+leaf_size];
            update(a, k-oldval);
        }
    }

    return 0;
}



