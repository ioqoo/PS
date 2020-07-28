#include <bits/stdc++.h>

const int MAX = 1 << ((int)ceil(log2(100000))+1);

using namespace std;

int N;
int tree[MAX];
int leaf_size;
int ans[100005];
vector<int> arr;

void init(){
    for (int i=leaf_size-1;i>=1;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(int pos, int diff){
    pos += leaf_size;
    tree[pos] += diff;
    while(pos > 1){
        pos /= 2;
        tree[pos] = tree[pos*2] + tree[pos*2+1];
    }
}

int getpos(int node, int l, int r, int remain){
    if (l==r) return l;
    int lc = tree[node*2];
    int rc = tree[node*2+1];
    int mid = (l+r)/2;
    if (remain <= lc){
        return getpos(node*2, l, mid, remain);
    } 
    else{
        return getpos(node*2+1, mid+1, r, remain-lc);
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    leaf_size = 1 << ((int)ceil(log2(N)));
    for (int i=0;i<N;i++){
        tree[i+leaf_size] = 1;
    }
    init();
    
    for (int i=0;i<N;i++){
        int currpos = getpos(1, 0, leaf_size-1, arr[i]+1);
        ans[currpos] = i+1;
        update(currpos, -1);
    }
    for (int i=0;i<N;i++){
        printf("%d\n", ans[i]);
    }
    
    return 0;
}



