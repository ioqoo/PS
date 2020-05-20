#include <iostream>
#include <cmath>
#include <vector>

#define ll long long
const int MAX = 1 << ((int)ceil(log2(100000))+1);
const int NMAX = 100005;

using namespace std;

int N, M, leaf_size;
ll tree[MAX];
ll lazy[MAX];
int st[NMAX], en[NMAX];
vector<int> graph[NMAX];
int order[NMAX];
int o;

void dfs(int node){
    st[node] = o++;
    for (int next: graph[node]){
        dfs(next);
    }
    en[node] = o-1;
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

ll find(int node, int l, int r, int s, int e){
    prop(node, l, r);
    if (r < s || e < l) return 0LL;
    if (s <= l && r <= e) return tree[node];
    int mid = (l + r) / 2;
    return find(node*2, l, mid, s, e) + find(node*2+1, mid+1, r, s, e);
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
    
    scanf("%d %d", &N, &M);
    leaf_size = 1 << ((int)ceil(log2(N)));
    int boss;
    for (int i=1;i<=N;i++){
        scanf("%d", &boss);
        if (i==1) continue;
        graph[boss].push_back(i);
    }
    
    dfs(1);
    
    int op, a;
    ll w;
    for (int i=0;i<M;i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %lld", &a, &w);
            update(1, 0, leaf_size-1, st[a], en[a], w);
        }
        else {
            scanf("%d", &a);
            printf("%lld\n", find(1, 0, leaf_size-1, st[a], st[a]));
        }
    }

    return 0;
}



