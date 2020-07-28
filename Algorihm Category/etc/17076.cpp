#include <bits/stdc++.h>

const int MAX = 1 << ((int)ceil(log2(200000))+1);

using namespace std;

int K, leaf_size, N, M;
int tree[MAX];
vector<int> arr;
int pmax[MAX]; // p[i] = max(arr[0] ~ arr[i-1])

void update(int ind, int diff){
    ind += leaf_size;
    tree[ind] += diff;
    while(ind>1){
        ind/=2;
        tree[ind] = tree[ind*2] + tree[ind*2+1];
    }
}

int find(int node, int l, int r, int remain){
    if (l==r) return l;
    int lc = tree[node*2];
    int mid = (l+r) / 2;
    if (lc < remain){
        return find(node*2+1, mid+1, r, remain-lc);
    }
    else{
        return find(node*2, l, mid, remain);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &K);
    int temp;
    leaf_size = 1 << (int)ceil(log2(200000));    
    for (int i=0;i<K;i++){
        scanf("%d", &temp);
        arr.push_back(temp);
        update(temp, 1);
    }
    int last_max = arr[0];
    for (int i=1;i<K;i++){
        pmax[i] = last_max;
        if (last_max < arr[i]) last_max = arr[i];
    }
    
    
    for (int i=0;i<K;i++){
        if (i==0) {
            update(arr[i], -1);
            continue;
        }
        update(arr[i], -1);
        int curr_M = arr[i];
        int curr_N = pmax[i];
//        printf("curr_M : %d / curr_N : %d\n", curr_M, curr_N);
        int deadline = find(1, 0, leaf_size-1, 2*curr_M);
//        printf("deadline: %d\n", deadline);
//        printf("M : %d / N : %d\n", M, N);
        if (deadline > curr_N) continue;
        if (curr_N < N) continue;
        else if (curr_N == N){
            if (curr_M > M){
                M = curr_M;
            }
        }
        else{
            N = curr_N;
            M = curr_M;
        }
    }
    if (N == 0 && M == 0) printf("-1\n");
    else printf("%d %d\n", N, M);

    return 0;
}



