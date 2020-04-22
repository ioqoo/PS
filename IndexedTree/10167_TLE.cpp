#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define MAX 3003
#define INF 1000000000000LL

using namespace std;

struct Node{
    ll l, r, lr, sum;
    Node operator = (const ll& n){
        l = r = lr = sum = n;
        return *this;
    }
    
    Node getsum(const Node& lc, const Node& rc){
        sum = lc.sum + rc.sum;
        l = max(lc.l, lc.sum + rc.l);
        r = max(rc.r, rc.sum + lc.r);
        lr = max(max(lc.r + rc.l, sum), max(lc.lr, rc.lr));
        return *this;
    }
    
    ll Max(){
        return max(max(l, r), max(lr, sum));
    }
};

struct Co{
    ll x, y, w;
    
    bool operator < (const Co &a){
        if (y == a.y) return x < a.x;
        return y < a.y;
    }
};

bool lbcmp(const Co &a, const Co &b){
    return a.y < b.y;
}

vector<Co> coors;
vector<ll> xco;
vector<ll> yco;
vector<ll> arr;
vector<Node> tree;

void clear(vector<Node> &tree){
    for (auto &p: tree){
        p.sum = p.l = p.r = p.lr = 0LL;
    }
}

Node init(int node, int l, int r){
    if (l == r) return tree[node] = arr[l];
    
    int mid = (l + r) / 2;
    return tree[node].getsum(init(node*2, l, mid), init(node*2+1, mid+1, r));
}

Node update(int node, int l, int r, int ind, ll val){
    if (!(l <= ind && ind <= r)) return tree[node];
    if (l == r) return tree[node] = val;
    int mid = (l + r) / 2;
    return tree[node].getsum(update(node*2, l, mid, ind, val), update(node*2+1, mid+1, r, ind, val));
}

ll getmax(int node, int l, int r, int s, int e){
    if (r < s || e < l) return -INF;
    if (s <= l && r <= e) return tree[node].Max();
    int mid = (l + r) / 2;
    return max(getmax(node*2, l, mid, s, e), getmax(node*2+1, mid+1, r, s, e));
}

int getind(vector<ll> &vt, ll x){
    return lower_bound(vt.begin(), vt.end(), x) - vt.begin();
}

void debug(){
    printf("current tree: ");
    for (auto &n: tree){
        printf("%lld ", n.Max());
    }
    printf("\n");
}

int N;

void debugarr(){
    printf("current arr: ");
    for (int i=0;i<N;i++)
        printf("%lld ", arr[i]);
    printf("\n");
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int tree_size = 1 << ((int)(ceil(log2(N))) + 1);
    tree = vector<Node>(tree_size, {-INF, -INF, -INF, -INF});
    arr.resize(N+1);
    
    ll x, y, w;
    for (int i=0;i<N;i++){
        scanf("%lld %lld %lld", &x, &y, &w);
        coors.push_back(Co{x, y, w});
        xco.push_back(x);
        yco.push_back(y);
    }
    
    sort(xco.begin(), xco.end());
    sort(yco.begin(), yco.end());
    xco.erase(unique(xco.begin(), xco.end()), xco.end());
    yco.erase(unique(yco.begin(), yco.end()), yco.end());
    
    for (auto &C: coors){ // C? &C?
        C.x = getind(xco, C.x);
        C.y = getind(yco, C.y);
    }
    
    sort(coors.begin(), coors.end());
    
    for (int i=0;i<=2;i++){
        arr[i] = coors[i].w;
    }
    
//    debug();
    
    
    ll ret = 0;
    ll yrange = coors.back().y;
    int s = 0;
    int i = 0;
    while(s <= yrange){
//        printf("==========\ns: %d\n\n", s);
        clear(tree);
        fill(arr.begin(), arr.end(), 0);
        i = lower_bound(coors.begin(), coors.end(), Co{0, s, 0}, lbcmp) - coors.begin();
        while (i < N){
            if (coors[i].y < s){
                i++;
                continue;
            }
//            printf("coors[i].y: %d\n", coors[i].y);
            auto C = coors[i];
            arr[C.x] = C.w;
//            debugarr();
            if (i+1 == N || coors[i+1].y != C.y) {
//                printf("***initiallized***\n");
                init(1, 0, N-1);
//                debug();
                ret = max(ret, getmax(1, 0, N-1, 0, N-1));
            }
            i++;
//            debug();
        }
        s++;
    }
    
    printf("%lld\n", ret);
    
    return 0;
}



