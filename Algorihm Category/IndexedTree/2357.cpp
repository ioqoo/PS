#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#define MAX 100005
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int leaf_size;
int arr[MAX];
int maxtree[266666];
int mintree[266666];

void maxinit(int node, int l, int r){
    for (int i=leaf_size-1;i>0;i--){
        maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
    }
}

void mininit(int node, int l, int r){
    for (int i=leaf_size-1;i>0;i--){
        mintree[i] = min(mintree[i*2], mintree[i*2+1]);
    }
}

int maxquery(int node, int s, int e, int l, int r){
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return maxtree[node];
    int mid = (l + r) / 2;
    return max(maxquery(node*2, s, e, l, mid), maxquery(node*2+1, s, e, mid+1, r));
}

int minquery(int node, int s, int e, int l, int r){
    if (r < s || e < l) return INF;
    if (s <= l && r <= e) return mintree[node];
    int mid = (l + r) / 2;
    return min(minquery(node*2, s, e, l, mid), minquery(node*2+1, s, e, mid+1, r));
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    leaf_size = 1 << ((int)ceil(log2(N)));
    
    memset(mintree, INF, sizeof(mintree));
    for (int i=0;i<N;i++){
        scanf("%d", &arr[i]);
        mintree[i+leaf_size] = maxtree[i+leaf_size] = arr[i];
    }
    
    
    maxinit(1, 0, N-1);
    mininit(1, 0, N-1);
    
    int a, b;
    for (int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        a--;b--;
        printf("%d %d\n", minquery(1, a, b, 0, leaf_size-1), maxquery(1, a, b, 0, leaf_size-1));
    }

    return 0;
}



