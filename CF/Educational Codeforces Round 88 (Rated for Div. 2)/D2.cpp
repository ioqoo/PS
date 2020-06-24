#include <bits/stdc++.h>

const int MAX = 400000;

using namespace std;

int N, leaf_size;
int sum_tree[MAX];
int max_tree[MAX];
int arr[MAX];

void suminit(){
    for (int i=0;i<N;i++){
        sum_tree[i+leaf_size] = arr[i];
    }
    for (int i=leaf_size-1;i>=1;i--){
        sum_tree[i] = sum_tree[i*2] + sum_tree[i*2+1];
    }
}

void maxinit(){
    for (int i=0;i<N;i++){
        max_tree[i+leaf_size] = arr[i];
    }    
    for (int i=leaf_size-1;i>=1;i--){
        max_tree[i] = max(max_tree[i*2], max_tree[i*2+1]);
    }
}

int getsum(int node, int l, int r, int s, int e){
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return sum_tree[node];
    int mid = (l + r) / 2;
    return getsum(node*2, l, mid, s, e) + getsum(node*2+1, mid+1, r, s, e);
}

int getmax(int node, int l, int r, int s, int e){
    if (r < s || e < l) return -50;
    if (s <= l && r <= e) return max_tree[node];
    int mid = (l + r) / 2;
    return max(getmax(node*2, l, mid, s, e) ,getmax(node*2+1, mid+1, r, s, e));
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    leaf_size = 1 << (int)ceil(log2(N));
    for (int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
    suminit();
    maxinit();
    
    int left = 0, right = 0;
    int ans = 0;
    while(left < N && right < N){
        int curr_sum = getsum(1, 0, leaf_size-1, left, right);
        int curr_max = getmax(1, 0, leaf_size-1, left, right);
//        printf("l : %d / r : %d / sum : %d / max : %d\n", left, right, curr_sum, curr_max);
        if (right == N-1){
            ans = max(ans, curr_sum - curr_max);
            left++;
            continue;
        }
        if (curr_sum < 0){
            left = right + 1;
            right = left;
        }
        else if (curr_sum - curr_max < 0){
            if (curr_max > getmax(1, 0, leaf_size-1, right+1, N-1)){
                left = right + 1;
                right = left;
            }
            else{
                ans = max(ans, curr_sum - curr_max);
                right++;
            }
        }
        else {
            ans = max(ans, curr_sum - curr_max);
            right++;
        }
    }
    printf("%d\n", ans);
    

    return 0;
}



