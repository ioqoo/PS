#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define pii pair<int, int>
#define MAX 100005

using namespace std;

int N, Q;
vector<int> nums;
int tree_size;

pii init(vector<int> &arr, vector<pii> &tree, int node, int s, int e){
    if (s==e) return tree[node] = pii(1, arr[s]);
    
    int mid = (s+e) / 2;
    
    pii LC = init(arr, tree, node*2, s, mid);
    pii RC = init(arr, tree, node*2+1, mid+1, e);
    
    if (LC.second == RC.second){
        return tree[node] = pii(LC.first + RC.first, RC.second);
    }
    else{
        if (LC.first > RC.first){
            return tree[node] = LC;
        }
        else{
            return tree[node] = RC;
        }
    }
}

pii get_freq(vector<pii> &tree, int node, int l, int r, int s, int e){
    if (e < l || r < s) return pii(0, 0);
    
    if (l <= s && e <= r) return tree[node];
    
    int mid = (s+e) / 2;
    
    pii LC = get_freq(tree, node*2, l, r, s, mid);
    pii RC = get_freq(tree, node*2+1, l, r, mid+1, e);
    
    if (LC.second == RC.second){
        return pii(LC.first + RC.first, RC.second);
    }
    else {
        if (LC.first > RC.first){
            return LC;
        }
        else{
            return RC;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    while(1){
        scanf("%d", &N);
        if (N == 0) break;
        scanf("%d", &Q);
        
        nums.clear();
        int num;
        for (int i=0;i<N;i++){
            scanf("%d", &num);
            nums.push_back(num);
        }
        tree_size = 1<<((int)ceil(log2(N))+1);
        vector<pii> segtree(tree_size);
        init(nums, segtree, 1, 0, N-1);
        pii temp = get_freq(segtree, 1, 0, N-1, 0, N-1);
        int a, b;
        for (int q=0;q<Q;q++){
            scanf("%d %d", &a, &b);
        }
        printf("%d %d\n", temp.first, temp.second);
    }

    return 0;

}
