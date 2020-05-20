#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 1 << ((int)ceil(log2(100000))+1);

int N, leaf_size;
int tree[400000];

void init(vector<int> &arr){
    for (int i=0;i<arr.size();i++){
        tree[i+leaf_size] = arr[i];
    }
    for (int i=leaf_size-1;i>=1;i--){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
}

int getMin(int node, int l, int r, int s, int e){
    if (r < s || e < l ) return INF;
    if (s <= l && r <= e) return tree[node];
    int mid = (l+r) / 2;
    return min(getMin(node*2, l, mid, s, e), getMin(node*2+1, mid+1, r, s, e));
}

int maxDifference(vector<int> px) {
    memset(tree, 0x3f3f3f3f, sizeof(tree));
    leaf_size = 1 << (int)(ceil(log2(px.size())));
    init(px);
    int ret = -1;
    for (int i=1;i<px.size();i++){
        int curr = px[i];
        int currmin = getMin(1, 0, leaf_size-1, 0, i-1);
        if (currmin >= curr) continue;
        ret = max(ret, curr-currmin);
    }
    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    
    scanf("%d", &N);
    vector<int> temp;
    int tt;
    for (int i=0;i<N;i++){
        scanf("%d", &tt);
        temp.push_back(tt);
    }
    printf("%d\n", maxDifference(temp));
}
