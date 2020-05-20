#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
const int MAX = 1 << ((int)ceil(log2(100000))+1);
const int NMAX = 100005;

using namespace std;

int N, M, leaf_size;
ll tree[MAX];
ll lazy[MAX];
vector<int> graph[NMAX];
int st[NMAX], en[NMAX];
int o;

void make_tree(int curr){
    st[curr] = ++o;
    for (int next: graph[curr]){
        make_tree(next);
    }
    en[curr] = o;
}

void prop(int node, int l, int r){
    if (lazy[node] != 0){
        if (node < leaf_size){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node] += (r-l+1) * lazy[node];
        lazy[node] = 0LL;
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
    
    scanf("%d %d", &N, &M);
    leaf_size = 1 << ((int)ceil(log2(N)));
    int parent;
    for (int i=1;i<=N;i++){
        scanf("%d", &parent);
        if (i==1) continue;
        graph[parent].push_back(i);
    }
    
    make_tree(1);
    
    int op, a;
    ll w;
    for (int i=0;i<M;i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %lld\n", &a, &w);
            update(1, 0, leaf_size-1, st[a]-1, en[a]-1, w);
        }
        else {
            scanf("%d", &a);
            printf("%lld\n", sum(1, 0, leaf_size-1, st[a]-1, st[a]-1));
        }
    }
    

    return 0;
}



