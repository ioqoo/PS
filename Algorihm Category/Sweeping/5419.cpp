#include <bits/stdc++.h>

#define pii pair<int, int>
#define ll long long
using namespace std;

const int MAX = 1 << ((int)ceil(log2(75000))+1);

struct co{
    int x, y;
};

int T, N, leaf_size;
int tree[MAX];
vector<co> coor;
vector<int> xco;
vector<int> yco;

bool cmp(const co &a, const co &b){
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void update(int ind, int diff){
    ind += leaf_size;
    tree[ind] += diff;
    while(ind > 1){
        ind /= 2;
        tree[ind] = tree[ind*2] + tree[ind*2+1];
    }
}

int sum(int node, int l, int r, int s, int e){
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return tree[node];
    int mid = (l+r) / 2;
    return sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        memset(tree, 0, sizeof(tree));
        coor.clear();
        xco.clear();
        yco.clear();
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            coor.push_back({x, y});
            xco.push_back(x);
            yco.push_back(y);
        }
        // grid compression
        sort(xco.begin(), xco.end());
        xco.erase(unique(xco.begin(), xco.end()), xco.end());
        sort(yco.begin(), yco.end());
        yco.erase(unique(yco.begin(), yco.end()), yco.end());
        int ymax = yco.size();
        leaf_size = 1 << (int)ceil(log2(ymax));
        
        for (int i=0;i<coor.size();i++){
            int x = coor[i].x, y = coor[i].y;
            coor[i].x = lower_bound(xco.begin(), xco.end(), x) - xco.begin();
            coor[i].y = lower_bound(yco.begin(), yco.end(), y) - yco.begin();
        }
        
        sort(coor.begin(), coor.end(), cmp);
        
        ll ans = 0;
        for (auto p: coor){
            ans += sum(1, 0, leaf_size-1, p.y, ymax);
            update(p.y, 1);
        }
        printf("%lld\n", ans);
        
    }

    return 0;
}



