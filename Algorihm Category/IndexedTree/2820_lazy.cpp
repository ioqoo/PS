#include <iostream>
#include <cmath>
#include <vector>

#define ll long long
const int MAX = 1 << ((int)(ceil(log2(500000)))+1);
//#define MAX 500005

using namespace std;

int N, M, leaf_size;
vector<int> graph[500005];
ll tree[MAX];
ll lazy[MAX];
int cnt;
int converted[500005];
ll pay[500005];
int st[500005], en[500005];

void dfs(int curr){
    st[curr] = ++cnt;
    converted[curr] = st[curr]-1;
    for (int next: graph[curr]){
        dfs(next);
    }
    en[curr] = cnt-1;
}

void init(){
    for (int i=leaf_size-1;i>0;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void prop(int node, int l, int r){
    if (lazy[node] != 0) {
        if (node < leaf_size){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node] += (r-l+1)*lazy[node];
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
    
    scanf("%d %d\n", &N, &M);
    leaf_size = 1 << ((int)ceil(log2(N)));
    ll a;
    int b; // pay, bossnum
    for (int i=1;i<=N;i++){
        if (i==1) {
            scanf("%lld\n", &a);
            pay[1] = a;
        }
        else{
            scanf("%lld %d\n", &a, &b);
            graph[b].push_back(i);
            pay[i] = a;
        }
    }
    dfs(1);
    
    for (int i=1;i<=N;i++){
        int newnum = converted[i];
        tree[newnum+leaf_size] = pay[i];
    }
    
    init();
//    debug();
    
    char op;
    int x;
    ll y;
    for (int i=0;i<M;i++){
        scanf("%c ", &op);
        if (op == 'p'){
            scanf("%d %lld\n", &x, &y);
            int l = st[x];
            int r = en[x];
            update(1, 0, leaf_size-1, l, r, y);
        }
        else{
            scanf("%d\n", &x);
            int newnum = converted[x];
            printf("%lld\n", find(1, 0, leaf_size-1, newnum, newnum));
        }
    }
    

    return 0;
}



