#include <bits/stdc++.h>

const int MAX = 1 << ((int)ceil(log2(100000))+1);

using namespace std;

int N, M, leaf_size;
int tree[MAX];

struct Q{
    int com, j, k;
    Q(int c, int j1): com(c), j(j1), k(0) {};
    Q(int c, int j1, int k1): com(c), j(j1), k(k1) {};
};

void update(int ind, int diff){
    ind += leaf_size;
    tree[ind] += diff;
    while(ind > 1){
        ind /= 2;
        tree[ind] = tree[ind*2] + tree[ind*2+1];
    }
}

int getsum(int node, int l, int r, int s, int e){
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return tree[node];
    int mid = (l+r) / 2;
    return getsum(node*2, l, mid, s, e) + getsum(node*2+1, mid+1, r, s, e);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        memset(tree, 0, sizeof(tree));
        cin >> N >> M;
        string com;
        int a, b;
        int arr[N] = {0,};
        vector<int> score;
        vector<Q> query;
        for (int i=0;i<M;i++){
            cin >> com;
            if (com == "R") {
                cin >> a >> b;
                a--;
                query.push_back({0, a, b});
                arr[a] += b;
                score.push_back(arr[a]);
            }
            else{
                cin >> a;
                a--;
                query.push_back({1, a});
            }
        }
        sort(score.begin(), score.end());
        score.erase(unique(score.begin(), score.end()), score.end());
        memset(arr, 0, sizeof(arr));
        int score_size = score.size();
        leaf_size = 1 << (int)(ceil(log2(score_size)));
        
        for (auto q: query){
            int com = q.com, j = q.j, k = q.k;
            if (com == 0){ // R
                int pos;
                if (arr[j] != 0){
                    pos = lower_bound(score.begin(), score.end(), arr[j]) - score.begin();
                    update(pos, -1);
                }
                arr[j] += k;
                pos = lower_bound(score.begin(), score.end(), arr[j]) - score.begin();
                update(pos, 1);
            }
            else{
                int pos = upper_bound(score.begin(), score.end(), arr[j]) - score.begin();
//                cout << "pos: " << pos << endl;
                int higher = getsum(1, 0, leaf_size-1, pos, leaf_size-1);
//                cout << "higher: " << higher << endl;
                cout << higher + 1 << "\n";
            }
        }
        
        
    }

    return 0;
}



