#include <bits/stdc++.h>

const int MAX = 1 << ((int)ceil(log2(100000))+1);
using namespace std;

int N, leaf_size;
int tree[MAX];

void update(int ind, int diff){
    ind += leaf_size;
    tree[ind] += diff;
    while(ind > 1){
        ind /= 2;
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
    
    int N;
    scanf("%d", &N);
    leaf_size = 1 << (int)ceil(log2(N));
    vector<int> height;
    vector<int> S;
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        height.push_back(temp);
        update(i, 1);
    }
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        S.push_back(temp);
    }
    sort(height.begin(), height.end());
    
    vector<int> ans;
    
    for (auto it=S.rbegin();it!=S.rend();it++){
        int curr = *it;
        int pos = find(1, 0, leaf_size-1, curr+1);
//        printf("%d\n", pos);
        ans.push_back(height[pos]);
        update(pos, -1);
    }
    for (auto it=ans.rbegin();it!=ans.rend();it++){
        printf("%d\n", (*it));
    }

    return 0;
}



